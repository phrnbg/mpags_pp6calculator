#include "PP6Day5MuonAnalysis.hpp"

// Standard Library
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
#include <vector>

// Third Party
#include "FileReader.hpp"

// This Project
#include "PP6Math.hpp"
#include "PP6Particle.hpp"
#include "PP6ParticleInfo.hpp"
#include "PP6FourVector.hpp"
#include "PP6ThreeVector.hpp"

//! Typedefs for this problem. Hidden in a namespace so they aren't global.
namespace InvMass {
//! A pair linking event id to a Particle
typedef std::pair<int, Particle> Event;

//! A vector to hold Events
typedef std::vector<Event> EventVector; 

//! A map between run name and vector of Events in that run
typedef std::map<std::string, std::vector<Event> > RunMap;

//! A multimap between Invariant Mass and the pair of Particles used
// to calculate that mass. Changes the multimap Compare comparison to
// std::greater<double> so masses are sorted in descending order.
typedef std::pair<Event, Event> InvMassPair;
typedef std::multimap<double, 
                      InvMassPair,
                      std::greater<double> > InvMassTable;
}

//! operator<< for InvMass Event
// This helps to print out results at the end
std::ostream& operator<<(std::ostream& out, const InvMass::Event& e) {
  out << "{" 
      << "Event : " << e.first << ", "
      << "Particle(" << e.second.getPDGCode()
      << ", " 
      << "(E, p) : " << e.second.getFourMomentum()
      << "}";
  return out;
}

//! IsNotPDGCode
// A simple Predicate functor whose operator() (function call operator)
// is overloaded to take a Event instance and return false if the
// Event's Particle does not have a PDG code matching that of the pdgCode_
// data member
// The constructor takes a PDG code.
class IsNotPDGCode {
 public:
  explicit IsNotPDGCode(int pdgCode) : pdgCode_(pdgCode) {;}
  ~IsNotPDGCode() {;}

  // return 
  bool operator()(const InvMass::Event& p) const {
    return (p.second).getPDGCode() != pdgCode_;
  }

 private:
  int pdgCode_;
};

// Function to read run based data from an input file, filling a
// supplied RunMap object using a supplied ParticleInfo database to get
// particle codes and masses.
bool read_run_data1(const std::string& runFile, const ParticleInfo& db, 
                   InvMass::RunMap& runTable) {
  // Open the file and check validity
  FileReader reader(runFile);
  if (!reader.isValid()) {
    std::cerr << "[read_run_data:error] "
              << runFile
              << " is not valid"
              << std::endl;  
    return false;
  }

  // read in one line to get rid of header
  reader.nextLine();

  // Now read in the particle/run data
  // Fields are:
  // event(int), name(string), px(double), py(double), pz(double),
  // run(string)
  std::string name(""), run("");
  int eventId(0);
  double px(0.0), py(0.0), pz(0.0);

  // Variable for use in the loop
  int pdgCode(0);

  while (reader.nextLine()) {
    eventId = reader.getField<int>(1);
    if (reader.inputFailed()) {
      std::cerr << "[read_run_data:error] Failed to to read event field from "
                << runFile
                << std::endl;
      return false;
    }

    name = reader.getField<std::string>(2);
    if (reader.inputFailed()) {
      std::cerr << "[read_run_data:error] Failed to to read name field from "
                << runFile
                << std::endl;
      return false;
    }

    px = reader.getField<double>(3);
    if (reader.inputFailed()) {
      std::cerr << "[read_run_data:error] Failed to to read p_x field from "
                << runFile
                << std::endl;
      return false;
    }

    py = reader.getField<double>(4);
    if (reader.inputFailed()) {
      std::cerr << "[read_run_data:error] Failed to to read p_y field from "
                << runFile
                << std::endl;
      return false;
    }

    pz = reader.getField<double>(5);
    if (reader.inputFailed()) {
      std::cerr << "[read_run_data:error] Failed to to read p_z field from "
                << runFile
                << std::endl;
      return false;
    }

    run = reader.getField<std::string>(6);
    if (reader.inputFailed()) {
      std::cerr << "[read_run_data:error] Failed to to read Data Source field from "
                << runFile
                << std::endl;
      return false;
    }

    // If all the data's been read in, we can fill the map.
    pdgCode = db.getPDGCode(name);

    // Create the particle and add it to the map.
    Particle tmp(pdgCode, px, py, pz);
    runTable[run].push_back(InvMass::Event(eventId,tmp));
  }

  return true;
}

class Cut {
  public:
    virtual ~Cut() {}

    virtual bool select(const int& event, InvMass::EventVector& run_events) = 0; 
 
};

bool Cut::select(const int& event, InvMass::EventVector& run_events){
    
    InvMass::EventVector::iterator requiredEvent = run_events.find(event);
    if (requiredRun == allRuns.end()) {
      std::cerr << "[pp6day4_muonanalysis:error] No " + event + " records found in "
                << muonFile
                << std::endl;
      return False;
    } else {
      return True;
    }   
}

int pp6day5_muonanalysis(){
    //Query the user fot the particle
    std::cout << "Enter the particle info: " << std::endl;
    std::cout << "Event?" << std::endl;
    int event = 2277; 

    // Query the user for the .dbt file, create the database and check it
    std::string dbtFilename;
    std::cout << "Enter path to .dbt file for initializing ParticleInfo: ";
    dbtFilename = getString();

    std::cout << dbtFilename << std::endl;
    const ParticleInfo& particleDB = ParticleInfo::Instance(dbtFilename);
    std::cout << "Checking ParticleInfo contains entries... ";
    if (!particleDB.size()) {
      std::cout << "fail" << std::endl;
      return 1;
    } else {
      std::cout << "ok" << std::endl;
    }

    // Query the user for the .dat file, and read in the information to
    // a RunMap instance
    //
    std::string muonFile;
    std::cout << "Enter filename to analyse: ";
    muonFile = getString();

    InvMass::RunMap allRuns;
 
    if (!read_run_data(muonFile, particleDB, allRuns)) {
      std::cerr << "[pp6day4_muonanalysis:error] Failed to read data from "
                << muonFile
                << std::endl;
      return 1;
    }

    //----------------------------------------------------------------------
    // Extract all mu- and mu+ particles that are in run4.dat
    InvMass::RunMap::iterator requiredRun = allRuns.find("run4.dat");
    if (requiredRun == allRuns.end()) {
      std::cerr << "[pp6day4_muonanalysis:error] No run4.dat records found in "
                << muonFile
                << std::endl;
      return 1;
    } 

    Cut cut_event;
    cut_event.select(event, allRuns);
    if cut_event == True:
       std::cout << "Event found" << std::endl;  
    
    return 0;
}

//! \file PP6ParticleInfo.hpp
//! \brief Declaration of Particle class
#ifndef PP6PARTICLEINFO_HPP
#define PP6PARTICLEINFO_HPP
#include <string>
#include <vector>
#include "PP6FourVector.hpp"
#include "PP6ThreeVector.hpp"

class ParticleInfo {
  public:
  // Constructors
  ParticleInfo(); // default ctor, so we can make arrays of them (p = 0)
  ParticleInfo(const ParticleInfo& other); // copy ctor
  ParticleInfo(const int pdg_code, const int charge, const int name, const double massMeV); // p = 0
  
  // Copy assignment operator
  ParticleInfo& operator=(const ParticleInfo& other);

  // Accessors
  int getPDGCode() const { return pdg_code_; }
  int getCharge() const { return charge_; }
  int getName() const { return name_; }
  double getMassMeV() const { return massMeV_; }
  
  // Set methods for pdg code, charge, name, massMeV, massGeV
  void setPDGCode(const int pdg_code) { pdg_code_ = pdg_code; }
  void setCharge(const int charge) { charge_ = charge; }
  void setName(const int name) { name_ = name; }
  void setMassMeV(const double massMeV) { massMeV_ = massMeV; }

 private:
  int pdg_code_;
  int charge_;
  int name_;
  double massMeV_;
};

#endif // PP6PARTICLE_HPP

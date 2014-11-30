#include "PP6Day4.hpp"
#include "PP6FourVector.hpp"
#include "PP6ParticleInfo.hpp"
#include "FileReaderTemplate.hpp"

#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include <vector>
#include <map>

#include "PP6Math.hpp"

void do_day4(){
  std::vector<int> event;
  std::vector<std::string> name;
  std::vector<std::string> run;
  std::vector<double> px;
  std::vector<double> py; 
  std::vector<double> pz;
  std::string path;

  // Obtain filename from user
  std::cout << "Enter filename to analyse: ";
  std::cin >> path;

  FileReaderTemplate file(path);
  std::vector<std::string> line;

  if (file.isValid()) {
     // Loop until out of lines
     while (file.nextLine()) {
     // Fields in each line line are treated as whitespace separated
     // and counted from 1. 

     for ( int i : line){
         event.push_back(file.getField(1, event));
         name.push_back(file.getField(2, name);
         px.push_back(file.getField(3, px));
         py.push_back(file.getField(4, py));
         pz.push_back(file.getfield(5, pz));
         run.push_back(file.getfield(6, run));
     }
     }
  }
}

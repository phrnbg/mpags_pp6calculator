#include "PP6Day5.hpp"
#include "PP6FourVector.hpp"
#include "PP6ParticleInfo.hpp"
#include "PP6Particle.hpp"
#include "FileReader.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <vector>
#include <string>

#include "PP6Math.hpp"
#include "PP6Day5MuonAnalysis.hpp"

void do_day5(){
  // Declare the variables
  // Variables for i/o
  double resultCode(0); 
  char op('\0');

  while (true)
  {
    // Ask the user what they want to do
    std::cout << "PP6Calculator - Day 5 Menu" << std::endl;
    std::cout << "==========================" << std::endl;
    std::cout << "Enter the operation you would like to perform:" << std::endl;
    std::cout << "1)  Select paticles" << std::endl;
    std::cout << "2)  " << std::endl;
    std::cout << "3)  " << std::endl;
    std::cout << "4)  " << std::endl;
    std::cout << "q)  Quit" << std::endl;
    std::cout << ">> ";
    
    std::cin >> op;
      
    // check for bad input
    if(!std::cin)
    {
      std::cerr << "[error] Error in input" << std::endl;
    
      // clear the buffer
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }

    // Handle menu operation
    if (op == 'q')
    {
      break;
    }
    else if (op == '1')
    {
      //resultCode = pp6day4_io_pdg();
    }
    else if (op == '2')
    {
      //resultCode = pp6day4_check_particleinfo();
    }
    else if (op == '3')
    {
      //resultCode = pp6day4_algorithm_demo();
    }
    else if (op == '4')
    {
      //resultCode = pp6day5_muonanalysis();
    }
    else
    {
      std::cerr << "[error] Operation '" << op << "' not recognised."
                << std::endl;
      continue;
    }

    // Handle any errors
    if (resultCode)
    {
      std::cerr << "[error] Operation '" << op 
                << "' returned a non-zero code '" << resultCode
                << "'. Please check parameters."
                << std::endl;
      resultCode = 0;
      continue;
    }
  }
}


#include "PP6Day3.hpp"
#include "FourVector.hpp"

#include <iostream>
#include <limits>
#include <string>
#include <fstream>

#include "PP6Math.hpp"

void do_day3(){
     char op('\0');
     while(true){
        // Ask the user what they want to do
        std::cout << "Enter the operation you would like to perform:" << std::endl;
        std::cout << "1) Boost a 4-Vector Along z" << std::endl;
        std::cout << "2) Calculate 4-Vector Length" << std::endl;
        std::cout << "3) Read data file" << std::endl;
        std::cout << "q) Quit" << std::endl;
        std::cout << ">> ";
        std::cin >> op;
     // check for bad input
     if(!std::cin){
        std::cerr << "[error] Error in input" << std::endl;
        // clear the buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
     } 
     if (op == 'q'){
        break;
     }

     else if(op == '1'){
          double time, sp_x, sp_y, sp_z, v;
          std::cout << "Enter the 4-Vector components: " << std::endl;
          time = getNumber();
          sp_x = getNumber();
          sp_y = getNumber();
          sp_z = getNumber();
          std::cout << "Enter the velocity: " << std::endl;
          v = getNumber();
          std::cout << "4-Vector: {" << time << "," << sp_x << "," << sp_y << "," << sp_z << "}" << std::endl;
          std::cout << "Boost velocity: v = " << v << " m/s" << std::endl;
          FourVector q(time, sp_x, sp_y, sp_z);
          q.boost_z(v);
          std::cout << "Boosted vector: {" << q.getT() << "," << q.getX() << "," << q.getY() << "," << q.getZ() << "}" << std::endl;
     }

     else if(op == '2'){
          double time, sp_x, sp_y, sp_z;
          std::cout << "Enter the 4-Vector components: " << std::endl;
          time = getNumber();
          sp_x = getNumber();
          sp_y = getNumber();
          sp_z = getNumber();
          std::cout << "4-Vector: {" << time << "," << sp_x << "," << sp_y << "," << sp_z << "}" << std::endl;
          FourVector q(time, sp_x, sp_y, sp_z);
          q.interval();
          std::cout << "Interval s = " << q.interval() << std::endl;          
     }
     else if(op == '3'){
          std::string path;
          std::cout << "Give the file path" << std::endl;
          std::cin >> path;
          std::string run;
          std::cout << "Give the run" << std::endl;
          std::cin >> run;
          std::string particle;
          std::cout << "Give the particle" << std::endl;
          std::cin >> particle;

          int size_p;
          int size_m;
          determine_size_array(path, run, particle, size_p, size_m);
          std::cout << "number of mu+ events: " << size_p << std::endl;
          std::cout << "number of mu- events: " << size_m << std::endl;

          double *px_p(new double[size_p]), *py_p(new double[size_p]), *pz_p(new double[size_p]);
          double *px_m(new double[size_m]), *py_m(new double[size_m]), *pz_m(new double[size_m]);
          int *event_p(new int[size_p]), *event_m(new int[size_m]);

          read_file(path, run, particle, event_p, px_p, py_p, pz_p, event_m, px_m, py_m, pz_m); 
     
     }else{
       std::cerr << "[error] Operation '" << op << "' not recognised." << std::endl;
       continue;
    }
    } 
}

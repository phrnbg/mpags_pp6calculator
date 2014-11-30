#include "PP6Day3.hpp"
#include "FourVector.hpp"
#include "Particle.hpp"

#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include <cmath>

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

          double mu_mass = 1.;
          double p_p, p_m, E_p, E_m, E, px, py, pz;
          double muonP, antimuonP;
          double *invariant_mass(new double[size_p*size_m]);
          double *muonPx(new double[size_p*size_m]), *muonPy(new double[size_p*size_m]), *muonPz(new double[size_p*size_m]);
          double *muonEnergy(new double[size_p*size_m]);
          double *antimuonPx(new double[size_p*size_m]), *antimuonPy(new double[size_p*size_m]), *antimuonPz(new double[size_p*size_m]);
          double *antimuonEnergy(new double[size_p*size_m]);
          int *muonEventNumber(new int[size_p*size_m]), *antimuonEventNumber(new int[size_p*size_m]);
          int *index(new int[size_p*size_m]);
          int counter = 0;
          for(int i = 0; i < size_p; i++){
             for(int j = 0; j < size_m; j++){
                 p_p = length(px_p[i], py_p[i], pz_p[i]);
                 p_m = length(px_m[j], py_m[j], pz_m[j]);
                 E_p = sqrt(pow(mu_mass,2) + pow(p_p,2));
                 E_m = sqrt(pow(mu_mass,2) + pow(p_m,2));
                 E = E_p + E_m;
                 px = px_p[i]+px_m[j];
                 py = py_p[i]+py_m[j];
                 pz = pz_p[i]+pz_m[j];
                 Particle q(E, px, py, pz);
                 invariant_mass[counter] = q.inv_mass();
                 std::cout << "The invariant mass is: m = " << invariant_mass[counter] << std::endl;
                 muonPx[counter] = px_p[i];
                 muonPy[counter] = py_p[i];
                 muonPz[counter] = pz_p[i];      
                 muonP = length(px_p[i], py_p[i], pz_p[i]);
                 muonEnergy[counter] = sqrt(pow(mu_mass,2) + pow(muonP,2));     
                 muonEventNumber[counter] = event_p[i];
                 antimuonPx[counter] = px_m[j];
                 antimuonPy[counter] = py_m[j];
                 antimuonPz[counter] = pz_m[j];
                 antimuonP = length(px_m[j], py_m[j], pz_m[j]); 
                 antimuonEnergy[counter] = sqrt(pow(mu_mass,2) + pow(antimuonP,2)); 
                 antimuonEventNumber[counter] = event_m[j];
                 index[counter] = counter;
                 counter++;
             }
          }

        associative_sort(invariant_mass, index, counter);
        for(int i = 0; i < 10; i++){    
            std::cout << "{InvariantMass : " << invariant_mass[index[i]]
                      << ",\n\t"
                      << "{Muon : "
                      << "Event = " << muonEventNumber[index[i]] << ", "
                      << "(E, P) = ("
                      << muonEnergy[index[i]] << ", "
                      << muonPx[index[i]] << ", "
                      << muonPy[index[i]] << ", "
                      << muonPz[index[i]] << ")}\n\t"
                      << "{AntiMuon : "
                      << "Event = " << antimuonEventNumber[index[i]] << ", "
                      << "(E, P) = ("
                      << antimuonEnergy[index[i]] << ", "
                      << antimuonPx[index[i]] << ", "
                      << antimuonPy[index[i]] << ", "
                      << antimuonPz[index[i]] << ")}\n"
                      << "}"
                      << std::endl;
        }

          delete [] px_p;
          delete [] py_p;
          delete [] pz_p;
          delete [] event_p;
          delete [] px_m;
          delete [] py_m;
          delete [] pz_m;
          delete [] event_m;
     
     }else{
       std::cerr << "[error] Operation '" << op << "' not recognised." << std::endl;
       continue;
    }
    } 
}

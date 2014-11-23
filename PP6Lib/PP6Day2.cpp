#include "PP6Day2.hpp"

#include <iostream>
#include <limits>
#include <cmath>
#include <string>

#include "PP6Math.hpp"
#include "FileReader.hpp"

void do_day2(){
    char op('\0');
    while(true){
      // Ask the user what they want to do
      std::cout << "Enter the operation you would like to perform:" << std::endl;
      std::cout << "1) Random energies and momenta" << std::endl;
      std::cout << "2) Read data file" << std::endl;
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

    else if (op == '1'){
        int size;
        double p[100], px[100], py[100], pz[100]; 
        double sum, m, E[100];
        double mean_energy, std_energy;        
        double max_E, max_p;
        //generate 100 random energies and momenta
        std::cout << "Enter number of vectors to generate: " << std::endl;
        size = getNumber();
        m = rand() % 100;
        for(int i = 0; i < size; i++){
           px[i] = rand() % 30;
           py[i] = rand() % 30;
           pz[i] = rand() % 30;  
           p[i] = length(px[i], py[i], pz[i]);
           E[i] = sqrt(pow(m,2) + pow(p[i],2));
        }

        sum = 0.0;
        for(int i = 0; i < size; i++){
           sum += E[i];
        }
        mean_energy = sum/size;

        sum = 0.0;
        for(int i = 0; i < size; i++){
            sum += pow((E[i] - mean_energy),2);
        }
        sum = sum/size;
        std_energy = sqrt(sum);
        std::cout << "The mean energy is: <E> = " << mean_energy << " +/- " << std_energy << std::endl;

        max_E = 0.0;
        max_p = 0.0;
        for(int i = 0; i < size; i++){
           if(E[i] > max_E){
              max_E = E[i];
           }
           if(p[i] > max_p){
              max_p = p[i];
           }
        }
        std::cout << "The maximum energy is: max_E = " << max_E << std::endl;
        std::cout << "The maximum momentum is: max_p = " << max_p << std::endl;
    }
    else if (op == '2'){
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
        double p_p, p_m, E_p, E_m, muonP, antimuonP;
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
               std::cout << "mu+ event: " << event_p[i] << "; mu- event: " << event_m[j] << std::endl;
               p_p = length(px_p[i], py_p[i], pz_p[i]);
               p_m = length(px_m[j], py_m[j], pz_m[j]);
               E_p = sqrt(pow(mu_mass,2) + pow(p_p,2));
               E_m = sqrt(pow(mu_mass,2) + pow(p_m,2));
               invariant_mass[counter] = inv_mass(E_p, px_p[i], py_p[i], pz_p[i], E_m, px_m[j], py_m[j], pz_m[j]);
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

    }

    else{
       std::cerr << "[error] Operation '" << op << "' not recognised." << std::endl;
       continue;
    }
    } 
}

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <algorithm>
#include <string>
#include "PP6Math.hpp"
#include "FileReader.hpp"

int main() {
    double res, res2;
    char op('\0');
    char day_op('\0');
    
    while(true){
       // Ask for the day
       std::cout << "Enter the operation you would like to perform:" << std::endl;
       std::cout << "1) 1st day" << std::endl;
       std::cout << "2) 2nd day" << std::endl;
       //std::cout << "3) 3rd day" << std::endl;
       //std::cout << "4) 4th day" << std::endl;
       //std::cout << "5) 5th day" << std::endl;
       //std::cout << "6) 6th day" << std::endl;
       std::cout << "q) Quit" << std::endl;
       std::cout << ">> ";
       std::cin >> day_op;
    if(!std::cin){
       std::cerr << "[error] Error in input" << std::endl;
       // clear the buffer
       std::cin.clear();
       std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       continue;
    }
    if (day_op == 'q'){
       break;
    }
    else if(day_op == '1'){  //day 1
       // Ask the user what they want to do
       std::cout << "Enter the operation you would like to perform:" << std::endl;
       std::cout << "1) Intercept" << std::endl;
       std::cout << "2) Quadratic Solver" << std::endl;
       std::cout << "3) Length of 3-Vector" << std::endl;
       std::cout << "4) Length of 4-Vector" << std::endl;
       std::cout << "5) Invariant Mass of Two Particles" << std::endl;
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

    else if(op == '1'){
       double m, q;
       //calculate the intercept of a line on the x-axis
       std::cout << "Give the slope" << std::endl;
       m = getNumber();
       std::cout << "Give the intercept" << std::endl;
       q = getNumber();;
       std::cout << "Straight line equation: y = " << m << "*x + (" << q << ")" << std::endl;
       res = intercept(m,q);
       std::cout << "The intercept on the x-axis is: " << res << std::endl;
       if (q==0){
          std::cerr << "[error] Divide by zero error" << std::endl;
          continue;
       } else {
          res = intercept(m, q);
       }
    }
    else if (op == '2'){
         double a, b, c;
         //solve a quadratic equation
         std::cout << "Give the first coefficient" << std::endl;
         a = getNumber();
         std::cout << "Give the second coefficient" << std::endl;
         b = getNumber();
         std::cout << "Give the third coefficient" << std::endl;
         c = getNumber();
         std::cout << "Quadratic equation:" << a << "*x**2 + (" << b << ")*x + (" << c << ") = 0" << std::endl;
         if (pow(b, 2) < (4 * a * c)){
             std::cerr << "[error]: No solutions possible (b^2 < 4ac)" << std::endl;
             continue;
         } if (a == 0) {
             std::cerr << "[error]: Divide by zero error (a=0)" << std::endl;
             continue;
         } else {
             res = quadratic(a, b, c, true);
             res2 = quadratic(a, b, c, false);
             std::cout << "The solutions are: x1 = " << res << "  x2 = " << res2 << std::endl;
         }
    } 
    else if (op == '3'){
         // Calculate sqrt(x^2+y^2+z^2)
         double x(0), y(0), z(0);
         // Ask user for vector components
         std::cout << "Enter the x-component: ";
         x = getNumber();
         std::cout << "Enter the y-component: ";
         y = getNumber();
         std::cout << "Enter the z-component: ";
         z = getNumber();
         res = length(x, y, z);
         std::cout << "The length is: l = " << res << std::endl;
    }
    else if (op == '4'){
         // Calculate sqrt(t^2 - (x^2+y^2+z^2))
         double x(0), y(0), z(0), t(0);
         // Ask user for vector components
         std::cout << "Enter the x-component: ";
         x = getNumber();
         std::cout << "Enter the y-component: ";
         y = getNumber();
         std::cout << "Enter the z-component: ";
         z = getNumber();
         std::cout << "Enter the t-component: ";
         t = getNumber();
         if (pow(t,2) < length(x, y, z)){
            std::cerr << "[error] Space-like component larger than Time-like" << std::endl;
            continue;
         }
         res = length(t, x, y, z);
         std::cout << "The length is: l = " << res << std::endl;
    }
    else if (op == '5'){
         double E1, E2, px1, py1, pz1, px2, py2, pz2;
         //calculate the invariant mass of two particles
         std::cout << "Give the two energies" << std::endl;
         std::cin >> E1 >> E2;
         std::cout << "Give the components of p1" << std::endl;
         std::cin >> px1 >> py1 >> pz1;
         std::cout << "Give the components of p2" << std::endl;
         std::cin >> px2 >> py2 >> pz2;

         if (pow(E1, 2) < length(px1, py1, pz1)){
            std::cerr << "[error]: Space-like component larger than Time-like for first particle" << std::endl;
            continue;
         }
         if (pow(E2, 2) < length(px2, py2, pz2)){
            std::cerr << "[error]: Space-like component larger than Time-like for second particle" << std::endl;
            continue;
         }
         res = inv_mass(E1, px1, py1, pz1, E2, px2, py2, pz2);
         std::cout << "The invariant mass is: m = " << res << std::endl;
    } 
    }
    else if(day_op == '2'){  //day 2
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
    else if (op == '1'){
         int size;
         double p[100], px[100], py[100], pz[100]; 
         double sum, m, E[100];
         double mean_energy, std_energy;        
         double max_E, max_p;
         //generate 100 random energies and momenta
         size = 100;
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
         std::cout << "The mean energy is: <E> = " << mean_energy << std::endl;

         sum = 0.0;
         for(int i = 0; i < size; i++){
             sum += pow((E[i] - mean_energy),2);
         }
         sum = sum/size;
         std_energy = sqrt(sum);
         std::cout << "The energy standard deviation is: sigma = " << std_energy << std::endl;

         max_E = 0.0;
         max_p = 0.0;
         for(int i = 0; i < size; i++){
            while(E[i] > max_E){
                 max_E = E[i];
            }
            while(p[i] > max_p){
                  max_p = p[i];
            }
         }
         std::cout << "The maximum energy is: max_E = " << max_E << std::endl;
         std::cout << "The maximum momentum is: max_p = " << max_p << std::endl;
    }
    else if (op == '2'){
  //       char path;
  //       std::cout << "Give the file path" << std::endl;
  //      std::cin >> path;
  //       path = "/home/anna/Scrivania/Cpp/observedparticles.dat";
         int size;
         int size_p = 0;
         int size_m = 0;
         size = determine_size_array(size_p, size_m);
         std::cout << size << std::endl;
         const int length1 = size_p;
         const int length2 = size_m;
         std::cout << "number of mu+ events: " << length1 << std::endl;
         std::cout << "number of mu- events: " << length2 << std::endl;
         double *px_p, *py_p, *pz_p;
         double *px_m, *py_m, *pz_m;
         int *event_p, *event_m;
         px_p = new double[length1];
         py_p = new double[length1];
         pz_p = new double[length1];
         event_p = new int[length1]; 
         px_m = new double[length1];
         py_m = new double[length1];
         pz_m = new double[length1];
         event_m = new int[length1]; 

         read_file(event_p, px_p, py_p, pz_p, event_m, px_m, py_m, pz_m);
         
         double mu_mass = 1.;
         double p_p, p_m, E_p, E_m;
         for(int i = 0; i <= 3; i++){
            for(int j = 0; j <= 3; j++){
                std::cout << "mu+ event: " << event_p[i] << "; mu- event: " << event_m[j] << std::endl;
                p_p = length(px_p[i], py_p[i], pz_p[i]);
                p_m = length(px_m[j], py_m[j], pz_m[j]);
                E_p = sqrt(pow(mu_mass,2) + pow(p_p,2));
                E_m = sqrt(pow(mu_mass,2) + pow(p_m,2));
                res = inv_mass(E_p, px_p[i], py_p[i], pz_p[i], E_m, px_m[j], py_m[j], pz_m[j]);
                std::cout << event_p[i] << std::endl;
                std::cout << "The invariant mass is: m = " << res << std::endl;                
            }
         }

    }

    else{
        std::cerr << "[error] Operation '" << op << "' not recognised." << std::endl;
        continue;
    }
    }
    }
    return 0;
}

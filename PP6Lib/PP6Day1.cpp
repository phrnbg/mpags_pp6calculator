#include "PP6Day1.hpp"

#include <iostream>
#include <limits>
#include <cmath>

#include "PP6Math.hpp"

void do_day1(){
     double res, res2;
     char op('\0');
     while(true){
        // Ask the user what they want to do
        std::cout << "PP6Calculator - Day 1 Menu" << std::endl;
        std::cout << "==========================" << std::endl;
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
     if (op == 'q'){
        break;
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
     else{
        std::cerr << "[error] Operation '" << op << "' not recognised." << std::endl;
        continue;
     }
     } 

}

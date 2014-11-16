#include "PP6Math.hpp"
#include "FileReader.hpp"

#include <string>
#include <iostream>
#include <limits>
#include <cmath>

double add(double a, double b){
       return a+b;
}

double subtract(double a, double b){
       return a-b;
}

double multiply(double a, double b){
       return a*b;
}

double divide(double a, double b){
       return a/b;
}

double intercept(double m, double c){
       return divide(-c, m);
}

double quadratic(double a, double b, double c, bool positiveRoot){
       double t(sqrt(pow(b, 2) - 4 * a * c));
       double res(0);
       if (positiveRoot){
          res = (-b + t) / (2 * a);
       } else {
          res = (-b - t) / (2 * a);
       }
       return res;
}

double length(double x, double y, double z){
        return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

double length(double t, double x, double y, double z){
       return sqrt(pow(t, 2) - pow(length(x, y, z), 2));
}

double inv_mass(double e1, double px1, double py1, double pz1, double e2, double px2, double py2, double pz2){
       double tot_e(e1 + e2);
       double tot_px(px1 + px2);
       double tot_py(py1 + py2);
       double tot_pz(pz1 + pz2);
       return length(tot_e, tot_px, tot_py, tot_pz);
}

double getNumber(){
       double res(0);
       std::cin >> res;
       while (!std::cin){
             std::cout << "Error in input. Please re-enter." << std::endl;
             // clear the buffer
             std::cin.clear();
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
             // retry
             std::cin >> res;
       }
       return res;
}

int determine_size_array(int* a, int* b){
    int size_p = 0;
    int size_m = 0;
    FileReader f("/home/anna/Scrivania/Cpp/observedparticles.dat");
    // Only process if the file is open/valid
    if (f.isValid()) {
    // Loop until out of lines
       while (f.nextLine()) {
       // Fields in each line line are treated as whitespace separated
       // and counted from 1. Fields can be retrieved as one of four main
       // types

       // retrieve field 2 as a float
       std::string b = f.getFieldAsString(2);

       // retrieve field 6 as a string
       std::string g = f.getFieldAsString(6);

       if(g == "run4.dat"){
          if(b == "mu+" ){
             size_p++;// = size + 1; 
           }
          if(b == "mu-" ){
           size_m++;// = size + 1; 
          }
       }
       // Check that input is o.k.
       if (f.inputFailed()) break;
       }
    }
    (*a) = size_p;
    (*b) = size_m;
    return (*a);
    return (*b);
//    return size_p, size_m;
}

double read_file(int* event_p, double* px_p, double* py_p, double* pz_p, int* event_m, double* px_m, double* py_m, double* pz_m){
         //int event_p, event_m;
         //double, px_p, py_p, pz_p, px_m, py_m, pz_m;
         int ip = 0;
         int im = 0;
         FileReader file("/home/anna/Scrivania/Cpp/observedparticles.dat");
         if (file.isValid()) {
         // Loop until out of lines
            while (file.nextLine()) {
            // Fields in each line line are treated as whitespace separated
            // and counted from 1. Fields can be retrieved as one of four main
            // types

            // retrieve field 2 as a float
            std::string b = file.getFieldAsString(2);

            // retrieve field 6 as a string
            std::string g = file.getFieldAsString(6);

            if(g == "run4.dat"){
              if(b == "mu+" ){
                 px_p[ip] = file.getFieldAsDouble(3);
                 py_p[ip] = file.getFieldAsDouble(4);
                 pz_p[ip] = file.getFieldAsDouble(5);
                 event_p[ip] = file.getFieldAsInt(1);
                 std::cout << event_p[im] << "  " << g << "  " << b << "   px = " << px_p[ip] << " py= " << py_p[ip] << " pz = " << pz_p[ip] << std::endl;
                 ip++;
//                 std::cout << ip << std::endl;
              }
              if(b == "mu-" ){
                 px_m[im] = file.getFieldAsDouble(3);
                 py_m[im] = file.getFieldAsDouble(4);
                 pz_m[im] = file.getFieldAsDouble(5);
                 event_m[im] = file.getFieldAsInt(1);
                 std::cout << event_m[im] << "  " << g << "  " << b << "   px = " << px_m[im] << " py= " << py_m[im] << " pz = " << pz_m[im] << std::endl;
                 im++;
//                 std::cout << im << std::endl; 
              }
            }
            // Check that input is o.k.
            if (file.inputFailed()) break;
            }  
         }
         return (*event_p);
         return (*px_p);
         return (*py_p);
         return (*pz_p);
         return (*event_m);
         return (*px_m);
         return (*py_m);
         return (*pz_m);
}

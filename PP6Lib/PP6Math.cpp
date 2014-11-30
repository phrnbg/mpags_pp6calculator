#include <string>
#include <iostream>
#include <limits>
#include <cmath>

#include "PP6Math.hpp"
#include "FileReader.hpp"
#include "PP6FourVector.hpp"

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

bool determine_size_array(const std::string& path, const std::string& run, const std::string& particle, int& a, int& b){
     int size_p = 0;
     int size_m = 0;
     FileReader f(path);
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

        if(g == run){
           if(b == particle + "+"){
              size_p++;
            }
           if(b == particle + "-"){
            size_m++;
           }
        }
        // Check that input is o.k.
        if (f.inputFailed()) break;
       }
     } else {
       return false;
     }
   
     a = size_p;
     b = size_m;
     return true;
}

bool read_file(const std::string& path, const std::string& run, const std::string& particle, int* event_p, double* px_p, double* py_p, double* pz_p, int* event_m, double* px_m, double* py_m, double* pz_m){
         int ip = 0;
         int im = 0;
         FileReader file(path);
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

            if(g == run){
              if(b == particle + "+"){
                 px_p[ip] = file.getFieldAsDouble(3);
                 py_p[ip] = file.getFieldAsDouble(4);
                 pz_p[ip] = file.getFieldAsDouble(5);
                 event_p[ip] = file.getFieldAsInt(1);
                 std::cout << event_p[im] << "  " << g << "  " << b << "   px = " << px_p[ip] << " py= " << py_p[ip] << " pz = " << pz_p[ip] << std::endl;
                 ip++;
              }
              if(b == particle + "-"){
                 px_m[im] = file.getFieldAsDouble(3);
                 py_m[im] = file.getFieldAsDouble(4);
                 pz_m[im] = file.getFieldAsDouble(5);
                 event_m[im] = file.getFieldAsInt(1);
                 std::cout << event_m[im] << "  " << g << "  " << b << "   px = " << px_m[im] << " py= " << py_m[im] << " pz = " << pz_m[im] << std::endl;
                 im++;
              }
            }
            // Check that input is o.k.
            if (file.inputFailed()) break;
            }  
         } else {
           return false;
         }

         return true;
}


int swap(double& a, double& b)
{
  double tmp(a);
  a = b;
  b = tmp;
  return 0;
}

int swap(int& a, int& b)
{
  int tmp(a);
  a = b;
  b = tmp;
  return 0;
}

int basic_sort(double *arr, int size)
{
  // Perform a bubble sort on the given array
  bool done(true);

  while (true)
  {
    done = true;

    for (int i = 0; i < size-1; ++i)
    {
      if (arr[i] < arr[i+1])
      {
        swap(arr[i], arr[i+1]);
        done = false;
      }
    }

    if (done)
    {
      break;
    }
  }
  return 0;
}

int associative_sort(double *arr, int *index, int size)
{
  // create a temporary array to sort on so we only change the index array
  double *arr_t = new double[size];
  for (int i(0); i < size; i++)
  {
    arr_t[i] = arr[i];
  }

  // Perform a bubble sort on the given array
  bool done(true);

  while (true)
  {
    done = true;

    for (int i(0); i < size-1; ++i)
    {
      if (arr_t[i] < arr_t[i+1])
      {
        swap(index[i], index[i+1]);
        swap(arr_t[i], arr_t[i+1]);
        done = false;
      }
    }
    if (done)
    {
      break;
    }
  }

  // delete temporary array, then return success
  delete [] arr_t;
  return 0;
}

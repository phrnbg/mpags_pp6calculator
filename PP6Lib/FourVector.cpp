// - FourVector.cpp
#include <sstream>
#include <string>
#include "FourVector.hpp"
#include <fstream>
#include <cmath>
#include <iostream>

//FourVector::FourVector() {t=0; x=0; y=0, z=0;}

FourVector::FourVector(const double& t_, const double& x_, const double& y_, const double& z_)
    : t(t_), x(x_), y(y_), z(z_)
{}

FourVector::FourVector(const FourVector& other)
    : t(other.t), x(other.x), y(other.y), z(other.z)
{}

double FourVector::interval(){
       double s = pow(t,2) - pow(x,2) - pow(y,2) - pow(z,2);
       return s;
}

double FourVector::boost_z(double v){
       double beta, gamma;
       const double c = 3.e8;
       beta = v/c;
       gamma = 1/sqrt(1-pow(beta,2));
       t = gamma*(t - (v*x)/pow(c,2));
       z = gamma*(z - v*t);
       return t;
       return z;
}

double FourVector::getT() const {  
    return t;
}

double FourVector::getX() const {  
    return x;
}

double FourVector::getY() const {  
    return y;
}

double FourVector::getZ() const {  
    return z;
}

/*void FourVector::setT(double a){
   t = a;
}

void FourVector::setX(double b){
   x = b;
}

void FourVector::setY(double c){
   y = c;
}

void FourVector::setZ(double d){
   z = d;
}*/

std::ostream& operator<<(std::ostream& stream, const FourVector& v){
   stream << "[";
   stream << v.getT() << ", " << v.getX() << ", ";
   stream << v.getY() << ", " << v.getZ() << "]";
   return stream;
}

/*
std::istream& operator>>(std::istream& stream, const FourVector& v){
   double a, b, c, d;
   stream >> a >> b >> c >> d;
   v.setT(a); v.setX(b); v.setY(c); v.setZ(d);
   return stream;
}*/

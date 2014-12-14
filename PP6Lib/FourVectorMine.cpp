// - FourVectormINE.cpp
#include <sstream>
#include <string>
#include "FourVectorMine.hpp"
#include <fstream>
#include <cmath>
#include <iostream>

//FourVectorMine::FourVectorMine() {t=0; x=0; y=0, z=0;}

FourVectorMine::FourVectorMine(const double& t_, const double& x_, const double& y_, const double& z_)
    : t(t_), x(x_), y(y_), z(z_)
{}

FourVectorMine::FourVectorMine(const FourVectorMine& other)
    : t(other.t), x(other.x), y(other.y), z(other.z)
{}

double FourVectorMine::interval(){
       double s = pow(t,2) - pow(x,2) - pow(y,2) - pow(z,2);
       return s;
}

double FourVectorMine::boost_z(double v){
       double beta, gamma;
       const double c = 3.e8;
       beta = v/c;
       gamma = 1/sqrt(1-pow(beta,2));
       t = gamma*(t - (v*x)/pow(c,2));
       z = gamma*(z - v*t);
       return 0;
}

double FourVectorMine::getT() const {  
    return t;
}

double FourVectorMine::getX() const {  
    return x;
}

double FourVectorMine::getY() const {  
    return y;
}

double FourVectorMine::getZ() const {  
    return z;
}

/*void FourVectorMine::setT(double a){
   t = a;
}

void FourVectorMine::setX(double b){
   x = b;
}

void FourVectorMine::setY(double c){
   y = c;
}

void FourVectorMine::setZ(double d){
   z = d;
}*/

std::ostream& operator<<(std::ostream& stream, const FourVectorMine& v){
   stream << "[";
   stream << v.getT() << ", " << v.getX() << ", ";
   stream << v.getY() << ", " << v.getZ() << "]";
   return stream;
}

/*
std::istream& operator>>(std::istream& stream, const FourVectorMine& v){
   double a, b, c, d;
   stream >> a >> b >> c >> d;
   v.setT(a); v.setX(b); v.setY(c); v.setZ(d);
   return stream;
}*/

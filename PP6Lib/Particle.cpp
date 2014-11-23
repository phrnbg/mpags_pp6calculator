// - Particle.cpp
#include <sstream>
#include <string>
#include "PP6Math.hpp"
#include "Particle.hpp"
#include <fstream>
#include <cmath>
#include <iostream>

Particle::Particle(const double& e_, const double& px_, const double& py_, const double& pz_)
    : e(e_), px(px_), py(py_), pz(pz_)
{}

Particle::Particle(const Particle& other)
    : e(other.e), px(other.px), py(other.py), pz(other.pz)
{}


double Particle::inv_mass(){
       return length(e, px, py, pz);
}


// - ParticleMine.cpp
#include <sstream>
#include <string>
#include "PP6Math.hpp"
#include "ParticleMine.hpp"
#include <fstream>
#include <cmath>
#include <iostream>

ParticleMine::ParticleMine(const double& e_, const double& px_, const double& py_, const double& pz_)
    : e(e_), px(px_), py(py_), pz(pz_)
{}

ParticleMine::ParticleMine(const ParticleMine& other)
    : e(other.e), px(other.px), py(other.py), pz(other.pz)
{}


double ParticleMine::inv_mass(){
       return length(e, px, py, pz);
}


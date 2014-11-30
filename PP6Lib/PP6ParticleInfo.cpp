#include "PP6ParticleInfo.hpp"
#include <cmath>

ParticleInfo::ParticleInfo()
: pdg_code_(0), charge_(0), name_(0), massMeV_(0.0)
{}

ParticleInfo::ParticleInfo(const ParticleInfo& other)
: pdg_code_(other.pdg_code_), charge_(other.charge_), name_(other.name_), massMeV_(other.massMeV_)
{}

ParticleInfo::ParticleInfo(const int pdg_code, const int charge, const int name, const double massMeV)
: pdg_code_(pdg_code), charge_(charge), name_(name), massMeV_(massMeV)
{}

ParticleInfo& ParticleInfo::operator=(const ParticleInfo& other)
{
if ( this != &other )
{
this->pdg_code_ = other.pdg_code_;
this->charge_ = other.charge_;
this->name_ = other.name_;
this->massMeV_ = other.massMeV_;
}
return *this;
}

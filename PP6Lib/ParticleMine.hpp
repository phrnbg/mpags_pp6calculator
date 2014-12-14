#ifndef PARTICLEMINE_HPP
#define PARTICLEMINE_HPP
#include <fstream>
#include <cmath>

class ParticleMine {
    public:
      ParticleMine(const double& e_, const double& px_, const double& py_, const double& pz_);

      ParticleMine(const ParticleMine& other);

      ~ParticleMine(){};

      //member functions
      double inv_mass();

    private:
      //member variables
      double e;
      double px;
      double py;
      double pz;
};

#endif // FOURVECTORMINE_HHP

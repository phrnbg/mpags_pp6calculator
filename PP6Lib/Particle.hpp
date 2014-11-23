#ifndef PARTICLE_HPP
#define PARTICLE_HPP
#include <fstream>
#include <cmath>

class Particle {
    public:
      Particle(const double& e_, const double& px_, const double& py_, const double& pz_);

      Particle(const Particle& other);

      ~Particle(){};

      //member functions
      double inv_mass();

    private:
      //member variables
      double e;
      double px;
      double py;
      double pz;
};

#endif // FOURVECTOR_HHP

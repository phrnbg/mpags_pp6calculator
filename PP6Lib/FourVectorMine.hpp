#ifndef FOURVECTORMINE_HPP
#define FOURVECTORMINE_HPP

#include <fstream>
#include <cmath>

class FourVectorMine {
    public:
      FourVectorMine(const double& t_, const double& x_, const double& y_, const double& z_);

      FourVectorMine(const FourVectorMine& other);

      ~FourVectorMine(){};

      //member functions
      double interval();
      double boost_z(double v);
      double getT() const;
      double getX() const;
      double getY() const;
      double getZ() const;
      //void setT(double& a);
      //void setX(double& b);
      //void setY(double& c);
      //void setZ(double& d);

    private:
      //member variables
      double t;
      double x;
      double y;
      double z;
};

#endif // FOURVECTORMINE_HHP

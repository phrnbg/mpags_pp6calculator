//! \file   PP6FourVector.hpp
//! \author Ben Morgan
//! \brief  Declaration of PP6FourVector
#ifndef PP6FOURVECTOR_HH
#define PP6FOURVECTOR_HH

// Standard Library
#include <string>

// This project
#include "PP6ThreeVector.hpp"

//! FourVector class
class FourVector {
 public: // we can use access specifiers as many times as we like
         // it's usually best to use this to break things up by
         // function, e.g. constants/typedefs first, then member functions
         // then member variables

  //! Causal structure enum
  enum CausalType {
    TIMELIKE = 0,
    SPACELIKE,
    LIGHTLIKE
  };

  //! Default constructor
  FourVector();

  //! Copy Constructor
  FourVector(const FourVector& other);

  //! Constructor with values
  FourVector(const double t, const double x, const double y, const double z);
  FourVector(const double t, const ThreeVector& v);



  //! Copy-assignment operator
  FourVector& operator=(const FourVector& other);

  //! Add a vector to this one
  FourVector& operator+=(const FourVector& rhs);

  //! Subtract a vector from this one
  FourVector& operator-=(const FourVector& rhs);

  //! Multiply components of this vector by a constant
  FourVector& operator*=(const double rhs);
  
  //! Divide components of this vector by a constant
  FourVector& operator/=(const double rhs);

  //! return the interval of the vector
  double interval() const;

  //! boost the vector along the z-axis [1]
  int boost_z(const double velocity);

  //! return the causal type of the vector
  CausalType getCausalType() const;

  //! return a string representation of this vector
  std::string asString() const;

  //! get t, x, y, z components of vector
  double getT() const {return t_;}
  const ThreeVector& getThreeVector() const {return x_;}
  double getX() const {return x_.getX();}
  double getY() const {return x_.getY();}
  double getZ() const {return x_.getZ();}

  //! set t, x, y, z components of vector
  void setT(const double t); 
  void setThreeVector(const ThreeVector& v);
  void setX(const double x);
  void setY(const double y);
  void setZ(const double z);

 private:
  //! constants, but only needed internally to FourVector
  static const double c;
  static const double c2;
 private:
  //! recompute interval whenever components change
  void compute_interval();
 private:
  //! member variables
  double t_;
  ThreeVector x_;
  double s_; // current interval
};

/*
 * [1] There are several design choices here, boost_z could be:
 * - a const member function, returning a boosted copy of the original
 * - a non-const member function, modifying the original (as shown)
 * - a free function taking a const FourVector and returning a boosted copy
 * - a free function taking a ref. to a FourVector and boosting it
 */

// We can keep the following free functions simply for convenience

//! Default Create a new FourVector instance
FourVector* createFourVector();

//! Create a new FourVector instance with components
FourVector* createFourVector(const double t, const double x, const double y,
                             const double z);

//! Destroy a FourVector instance, nulling the supplied pointer
void destroyFourVector(FourVector *&p);

//! convert a CausalType to a string representation
std::string asString(const FourVector::CausalType k);

//! Free I/O streaming operators
std::istream& operator>>(std::istream& in, FourVector& vec);
std::ostream& operator<<(std::ostream& out, const FourVector& vec);

//! Free arithmetic operators
FourVector operator+(const FourVector& lhs, const FourVector& rhs);
FourVector operator-(const FourVector& lhs, const FourVector& rhs);
FourVector operator*(const FourVector& lhs, const double rhs);
FourVector operator*(const double lhs, const FourVector& rhs);
FourVector operator/(const FourVector& lhs, const double rhs);

double contraction(const FourVector& lhs, const FourVector& rhs);

#endif // PP6FOURVECTOR_HH


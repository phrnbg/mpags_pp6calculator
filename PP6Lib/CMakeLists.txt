# - CMake script for pp6lib library
#
add_library(pp6lib STATIC 
  PP6Math.hpp 
  PP6Math.cpp
  PP6Day1.hpp 
  PP6Day1.cpp
  PP6Day2.hpp 
  PP6Day2.cpp
  PP6Day3.hpp 
  PP6Day3.cpp
  PP6Day4.hpp
  PP6Day4.cpp
  PP6ThreeVector.hpp
  PP6ThreeVector.cpp
  PP6FourVector.hpp
  PP6FourVector.cpp
  PP6Particle.hpp
  PP6Particle.cpp
  PP6ParticleInfo.hpp
  PP6ParticleInfo.cpp
  FourVector.hpp
  FourVector.cpp
  Particle.hpp
  Particle.cpp
  FileReaderTemplate.hpp
  FileReaderTemplate.cpp
  )
add_library(FileReader FileReader.hpp FileReader.cpp)

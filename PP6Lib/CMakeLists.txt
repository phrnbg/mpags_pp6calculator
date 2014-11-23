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
  FourVector.hpp
  FourVector.cpp
  )
add_library(FileReader FileReader.hpp FileReader.cpp)

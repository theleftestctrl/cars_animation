#ifndef BUILDER_H
#define BUILDER_H
#include "car.hpp"
#include "road.hpp"
#include <iterator>
#include <random>

class Builder {
  public:
    Builder(double meanDistance, 
            double stdDistance, 
            double meanVelocity, 
            double stdVelocity, 
            double meanCarLength, 
            double stdCarLength);
    Builder();
    int makeRoad(double lenghtRoad);

    Car createCar();

    Road getRoad();

  private:
    double _currentCar = 0;
    double _beforePosition = 0;
    double _meanDistance;
    double _stdDistance; 
    double _meanVelocity; 
    double _stdVelocity; 
    double _meanCarLength; 
    double _stdCarLength;

    std::default_random_engine _generator;

    Road _road;
};




#endif //BUILDER_H
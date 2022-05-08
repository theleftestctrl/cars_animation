#include "builder.hpp"

Builder::Builder (double meanDistance, 
            double stdDistance, 
            double meanVelocity, 
            double stdVelocity, 
            double meanCarLength, 
            double stdCarLength){
  _meanDistance = meanDistance;
  _stdDistance = stdDistance;
  _meanVelocity = meanVelocity;
  _stdVelocity = stdVelocity;
  _meanCarLength = meanCarLength;
  _stdCarLength = stdCarLength;
            }

Car Builder::createCar(){
  std::normal_distribution<double> dist(_meanDistance, _stdDistance);
  double currentPosition = _beforePosition + dist(_generator);
  _beforePosition = currentPosition;

  std::normal_distribution<double> vel(_meanVelocity, _stdVelocity);
  double velocity = vel(_generator);

  std::normal_distribution<double> len(_meanCarLength, _stdCarLength);
  double length = len(_generator);
  
  Car car = Car(_currentCar++, currentPosition, velocity, length);
  return car;
}

int Builder::makeRoad(double lenghtRoad){
  _road = Road(lenghtRoad);
  while (_beforePosition < lenghtRoad){
    Car newCar = createCar();
    if (newCar.getCoordinate() < lenghtRoad){
      _road.addCar(newCar);
    }else{
      break;
    }
    
  }
  return 0;
}

Road Builder::getRoad(){
  return _road;
}
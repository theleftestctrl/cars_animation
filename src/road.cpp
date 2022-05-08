#include "road.hpp"


Road::Road(double _lenghtRoad){
  lenghtRoad = _lenghtRoad;
}

Road::Road(){
  
}

void Road::addCar(Car car){
  _cars.push_back(car);
}
  
std::vector<Car> Road::getCars(){
  return Road::_cars;
}

Car* Road::getCar(int carInd){
  return &_cars[carInd];
}

int Road::carCount(){
  return _cars.size();
}

double Road::getLenghtRoad(){
  return lenghtRoad;
}

void Road::printRoad(){
  for (Car car : _cars){
    car.printDataCar();
  }
}

std::string Road::getDataRoad(){
  std::string dataRoad = "";
  for (Car car : _cars){
    dataRoad = dataRoad.append(car.getDataCar());
  }

  return dataRoad;
}

void Road::sortRoad(){
  sort(_cars.begin(), _cars.end(), comp);
}

bool Road::comp(Car a, Car b){
  return a.getCoordinate() < b.getCoordinate();
}

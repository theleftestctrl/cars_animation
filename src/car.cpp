#include "car.hpp"

Car::Car(int id, double coordinate, double velocity, double length){
  _id = id;
  _coordinate = coordinate;
  _velocity = velocity;
  _length = length;
}

int Car::getId(){
  return _id;
}

void Car::printDataCar(){
  std::cout << "ID:" << _id << ";" << std::endl;
  std::cout << "Coordinate: " << _coordinate << ";" << std::endl;
  std::cout << "Velocity: " << _velocity << ";" << std::endl;
  std::cout << "Length: " << _length << ";" << std::endl;
}

std::string Car::getDataCar(){
  std::string carData = "";
  carData = carData.append(std::to_string(_id));
  carData = carData.append(" ");
  carData = carData.append(std::to_string(_coordinate));
  carData = carData.append(" ");
  carData = carData.append(std::to_string(_velocity));
  carData = carData.append(" ");
  carData = carData.append(std::to_string(_length));
  carData = carData.append("\n");

  return carData;
}

void Car::setVelocity(double velocity){
  _velocity = velocity;
}

double Car::getVelocity(){
  return _velocity;
}

void Car::setCoordinate(double coordinate){
  _coordinate = coordinate;
}

double Car::getCoordinate(){
  return _coordinate;
}

double Car::getLength(){
  return _length;
}

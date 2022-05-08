#include "solver.hpp"

Solver::Solver(Road* road, double deltaT){
  _road = road;
  _deltaT = deltaT;
}

void Solver::setA(double a){
  _a = a;
}

void Solver::setB(double b){
  _b = b;
}

void Solver::setL(double l){
  _l = l;
}
void Solver::setС(double c){
  _c = c;
}

double Solver::getDistance(Car* a, Car* b){
  return std::abs(a->getCoordinate() - b->getCoordinate());
}

double Solver::velocityFunction(double distance){
  return _a + _c*atan((distance - _b) / _l);
}

void Solver::stepVelocity(){
  for (int i = 0; i < _road->carCount() - 1; i++){
    _road->getCar(i)->setVelocity(velocityFunction(getDistance(_road->getCar(i), _road->getCar(i + 1))));
    }
  double distance0 = _road->getLenghtRoad() - getDistance(_road->getCar(0), _road->getCar(_road->carCount()));
  _road->getCar(_road->carCount())->setVelocity(velocityFunction(distance0));
}

void Solver::stepCoordinate(){
  for (int i = 0; i < _road->carCount(); i++){
    double newPositionCar = _road->getCar(i)->getCoordinate() + _road->getCar(i)->getVelocity()*_deltaT;
    if (newPositionCar >= _road->getLenghtRoad()){
      _road->getCar(i)->setCoordinate(newPositionCar - _road->getLenghtRoad());
    }else{
      _road->getCar(i)->setCoordinate(newPositionCar);
    }
  }
}

void Solver::timeMove(){
  stepCoordinate();
  stepVelocity();
  _timeCount += _deltaT;
  _countStep++;
}

void Solver::dump(std::string filename){
  std::string dump = "";
  dump = dump.append("slide: ");
  dump = dump.append(std::to_string(_countStep));
  dump = dump.append("\n");
  dump = dump.append("cars: ");
  dump = dump.append(std::to_string(_road->carCount()));
  dump = dump.append("\n");
  dump = dump.append("road length: ");
  dump = dump.append(std::to_string(_road->getLenghtRoad()));
  dump = dump.append("\n");
  dump = dump.append("ID  Coordinate  Velocity  Length");
  dump = dump.append("\n");
  dump = dump.append(_road->getDataRoad());

  std::ofstream file;
  if (_countStep == 0){
    file.open(filename, std::ios_base::trunc);
  }else{
    file.open(filename, std::ios_base::app);
  }
  
  file << dump;
  file.close();
  
}

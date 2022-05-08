#include "car.hpp"
#include "solver.hpp"
#include "builder.hpp"
#include <iostream>
#include <string.h>

int main() {

  std::string fileDump = "dump.out";
  
  double meanDistance = 50;
  double stdDistance = 2;
  
  double meanVelocity = 25;
  double stdVelocity = 5;
  
  double meanCarLength = 5;
  double stdCarLength = 1;

  double lenghtRoad = 1000;

  double deltaT = 0.01;

  Builder builder = Builder(meanDistance, stdDistance, meanVelocity, stdVelocity, meanCarLength, stdCarLength);
  int status = builder.makeRoad(lenghtRoad);
  Road road = builder.getRoad();
  Solver solver = Solver(&road, deltaT);
  road.printRoad();
  
  for(int i = 0; i < 1000; i++){
    solver.dump(fileDump);
    solver.timeMove();
  }
  solver.dump(fileDump);
}

  #ifndef SOLVER_H
#define SOLVER_H

#include "road.hpp"
#include <math.h>
#include <fstream>
class Solver{
  public:
    Solver(Road* road, double deltaT);
    void timeMove();
    void setA(double a);
    void setB(double b);
    void setL(double l);
    void setС(double с);
    void dump(std::string filename);

  private:
    double velocityFunction(double distance);
    double getDistance(Car* a, Car* b);
    void stepCoordinate();
    void stepVelocity();
    Road* _road;
    int _countStep = 0;
    double _timeCount = 0.0;
    double _minDistance;
    double _deltaT;
    // double Solver::velocityFunction(double distance){
  //return _a + _c*atan((distance - _b) / _l);
//}
    double _a = 12.0;
    double _b = 18.0;
    double _l = 9.0;
    double _c = 8.0;

};
#endif //SOLVER_H

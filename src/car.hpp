#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

class Car {
  public:
    Car();
    Car(int id, double coordinate, double velocity, double length);

    void printDataCar();
    std::string getDataCar();
    
    void setVelocity(double velocity);
    double getVelocity();

    void setCoordinate(double coordinate);
    double getCoordinate();

    double getLength();
    int getId();
    
    
  private:
    int _id;
    double _velocity;
    double _coordinate;
    double _length;

};

#endif //CAR_H

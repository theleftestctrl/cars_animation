#ifndef ROAD_H
#define ROAD_H

#include "car.hpp"
#include <vector>
#include <algorithm>
#include <string>

class Road{
  public:
    Road(double _lenghtRoad);
    Road();
    void addCar(Car car);
    std::vector<Car> getCars();
    Car* getCar(int carInd);
    int carCount();
    void printRoad();
    std::string getDataRoad();
    double getLenghtRoad();

  private:
    static bool comp(Car a, Car b);
    void sortRoad();
    std::vector<Car> _cars;
    double lenghtRoad;
};

#endif //ROAD_H
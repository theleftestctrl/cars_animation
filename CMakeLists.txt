cmake_minimum_required(VERSION 3.19) 
project(traffic)

add_executable(traffic main.cpp car.hpp car.cpp road.hpp road.cpp solver.hpp solver.cpp builder.hpp builder.cpp)

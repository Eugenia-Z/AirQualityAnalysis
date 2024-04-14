cmake_minimum_required(VERSION 3.27)
project(Final_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp
        VectorLinkedList.cpp
        AirQuality.cpp
        MonthlyData.cpp)
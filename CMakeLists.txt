cmake_minimum_required(VERSION 3.27)
project(AirQualityAnalysis_0410_gyp_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp
        VectorLinkedList.cpp
        AirQuality.cpp
        MonthlyData.cpp)
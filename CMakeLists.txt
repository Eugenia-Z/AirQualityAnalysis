cmake_minimum_required(VERSION 3.27)
project(Final_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp
        VectorLinkedList.cpp
        AirQuality.cpp
        MonthlyData.cpp
        Time.cpp
        Time.h
        Date.cpp
        Date.h
        AirQuality.cpp
        AirQuality.h
)

add_executable(testDateTimeAirQuality testDateTimeAirQuality.cpp
        Time.cpp
        Time.h
        Date.cpp
        Date.h
        AirQuality.cpp
        AirQuality.h
)


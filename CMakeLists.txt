cmake_minimum_required(VERSION 3.27)
project(Final_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp
        Time.cpp
        Date.cpp
        Date.h
        AirQuality.h
        AirQuality.cpp
        MonthlyData.h
        MonthlyData.cpp
        AirQualityAnalyzer.h
        AirQualityAnalyzer.cpp
        VectorLinkedList.h
        VectorLinkedList.cpp
        AirQualityAnalyzer.cpp
)

add_executable(testDateTimeAirQuality testDateTimeAirQuality.cpp
        Time.cpp
        Date.cpp
        AirQuality.cpp
)

add_executable(testAirQualityAnalyzer testAirQualityAnalyzer.cpp
        Time.cpp
        Time.h
        Date.cpp
        Date.h
        AirQuality.h
        AirQuality.cpp
        MonthlyData.h
        MonthlyData.cpp
        AirQualityAnalyzer.h
        AirQualityAnalyzer.cpp
        VectorLinkedList.h
        VectorLinkedList.cpp
)

add_executable(testMonthlyData testMonthlyData.cpp
        VectorLinkedList.cpp
        AirQuality.cpp
        MonthlyData.cpp
        Time.cpp
        Date.cpp
        AirQualityAnalyzer.cpp)

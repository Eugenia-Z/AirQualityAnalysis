cmake_minimum_required(VERSION 3.27)
project(Final_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp
        Time.cpp
        Date.cpp
        AirQuality.cpp
        VectorLinkedList.cpp
        MonthlyData.cpp
        AirQualityAnalyzer.cpp
)

add_executable(testDateTimeAirQuality testDateTimeAirQuality.cpp
        Time.cpp
        Date.cpp
        AirQuality.cpp
)

add_executable(testVector testVector.cpp
        Date.cpp
        Time.cpp
        AirQuality.cpp
        VectorLinkedList.cpp
)

add_executable(testMonthlyData testMonthlyData.cpp
        Time.cpp
        Date.cpp
        AirQuality.cpp
        VectorLinkedList.cpp
        MonthlyData.cpp
)

add_executable(testAirQualityAnalyzer testAirQualityAnalyzer.cpp
        Time.cpp
        Date.cpp
        AirQuality.cpp
        VectorLinkedList.cpp
        MonthlyData.cpp
        AirQualityAnalyzer.cpp
)

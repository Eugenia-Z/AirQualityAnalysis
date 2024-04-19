cmake_minimum_required(VERSION 3.27)
project(AirQualityAnalysis)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp
        VectorLinkedList.cpp
        AirQuality.cpp
        MonthlyData.cpp
        Time.cpp
        Date.cpp
        AirQualityAnalyzer.cpp)

add_executable(testDateTimeAirQuality testDateTimeAirQuality.cpp
        Time.cpp
        Date.cpp
        AirQuality.cpp
)

add_executable(testAirQualityAnalyzer testAirQualityAnalyzer.cpp)

add_executable(testMonthlyData testMonthlyData.cpp
        VectorLinkedList.cpp
        AirQuality.cpp
        MonthlyData.cpp
        Time.cpp
        Date.cpp
        AirQualityAnalyzer.cpp)
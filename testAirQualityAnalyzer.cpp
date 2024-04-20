#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "AirQuality.h"
#include "Date.h"
#include "MonthlyData.h"
#include "Time.h"
#include "AirQualityAnalyzer.h"
#include "VectorLinkedList.h"
using namespace std;

int main(){
    AirQualityAnalyzer analyzer;
    //test runAnalysis, readCSV, and doubleValidator
    analyzer.readCSV("../AirQualityUCI.csv");
    //test printAllAvg
    analyzer.printAllAvg();
    analyzer.printAllMax();
    //print monthlyData of the ith month
    analyzer.printMonth(0);
    analyzer.printMonth(13);
    //test user input
    analyzer.processInputMonth();
    analyzer.processInputDate();
    analyzer.processInputTime();
    //test get and print data
    analyzer.getMonthAvgTemp(6);
    analyzer.getMonthAvgRH(6);
    analyzer.getMonthAvgAH(6);
    analyzer.getMonthMaxTemp(6);
    analyzer.getMonthMaxRH(6);
    analyzer.getMonthMaxAH(6);
    analyzer.displayMonthHigherThanAvgTemp(6);
    analyzer.displayMonthHigherThanAvgRH(6);
    analyzer.displayMonthHigherThanAvgAH(6);
    analyzer.displayDataAtDate();
}

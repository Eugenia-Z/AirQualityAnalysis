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
    analyzer.runAnalysis("../AirQualityUCI.csv");
    //test getMonths
    MonthlyData* months = analyzer.getMonths();
    //test getNumMonths
    int numMonths = analyzer.getNumMonths();
    //test printAllAvg
    analyzer.printAllAvg();
    analyzer.printAllMax();
    //print monthlyData of the ith month
    analyzer.printMonth(0);
    analyzer.printMonth(13);
    months[0].displayHigherThanAvgTemp();
    months[0].displayHigherThanAvgRH();
    months[0].displayHigherThanAvgAH();
}

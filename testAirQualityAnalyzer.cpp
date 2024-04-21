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

int main() {
    AirQualityAnalyzer analyzer;

    // test runAnalysis, readCSV, and doubleValidator
    analyzer.readCSV("../AirQualityUCI.csv");

    // test printAllAvg
    analyzer.printAllAvg();
    analyzer.printAllMax();

    // print monthlyData
    analyzer.printMonth();
    analyzer.printMonth();

    // test user input
    cout << "test user input ..." << endl;
    analyzer.processInputMonth();
    analyzer.processInputDate();
    analyzer.processInputTime();

    //  test get and print data
    cout << "test get and print avg data...." << endl;
    analyzer.printMonthAvgTemp();
    analyzer.printMonthAvgRH();
    analyzer.printMonthAvgAH();

    cout << "test get and print max data...." << endl;
    analyzer.printMonthMaxTemp();
    analyzer.printMonthMaxRH();
    analyzer.printMonthMaxAH();
    analyzer.displayMonthHigherThanAvgTemp();
    analyzer.displayMonthHigherThanAvgRH();
    analyzer.displayMonthHigherThanAvgAH();
    analyzer.displayDataAtDate();
}

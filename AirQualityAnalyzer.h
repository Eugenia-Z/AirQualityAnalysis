#ifndef FINAL_PROJECT_AIRQUALITYANALYZER_H
#define FINAL_PROJECT_AIRQUALITYANALYZER_H
#include "MonthlyData.h"
#include <string>
using namespace std;

class AirQualityAnalyzer {
public:
    //read input
    void readCSV(const string& fileName);
    //print data (for test purpose)
    void printAllAvg()const;
    void printAllMax()const;
    void printMonth(int i);
    //deal with user input
    int processInputMonth();
    Date processInputDate();
    Time processInputTime();
    //get and print data
    double getMonthAvgTemp(int index);
    double getMonthAvgRH(int index);
    double getMonthAvgAH(int index);
    double getMonthMaxTemp(int index);
    double getMonthMaxRH(int index);
    double getMonthMaxAH(int index);
    void displayMonthHigherThanAvgTemp(int index);
    void displayMonthHigherThanAvgRH(int index);
    void displayMonthHigherThanAvgAH(int index);
    void displayDataAtDate();

private:
    // number of total months capacity
    static const int NUM_MONTHS = 14;
    // array of MonthlyData
    MonthlyData months[NUM_MONTHS];
    // index works as pointer to store data into array
    int monthsIndex = -1;
    // validate double value in input
    bool doubleValidator(const string& doubleString);
};

#endif //FINAL_PROJECT_AIRQUALITYANALYZER_H

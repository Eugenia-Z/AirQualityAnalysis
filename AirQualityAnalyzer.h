#ifndef FINAL_PROJECT_AIRQUALITYANALYZER_H
#define FINAL_PROJECT_AIRQUALITYANALYZER_H
#include "MonthlyData.h"
#include <string>
using namespace std;

class AirQualityAnalyzer {
public:
    void runAnalysis(const string& fileName);
    MonthlyData* getMonths();
    int getNumMonths();
    void printAllAvg()const;
    void printAllMax()const;
    void printMonth(int i);
    int processInputMonth();
    double getMonthAvgTemp(int index);
    double getMonthAvgRH(int index);
    double getMonthAvgAH(int index);
    double getMonthMaxTemp(int index);
    double getMonthMaxRH(int index);
    double getMonthMaxAH(int index);
    void displayMonthHigherThanAvgTemp(int index);
    void displayMonthHigherThanAvgRH(int index);
    void displayMonthHigherThanAvgAH(int index);

private:
    static const int NUM_MONTHS = 14;
    MonthlyData months[NUM_MONTHS];
    int monthsIndex = -1;
    void readCSV(const string& fileName);
    bool doubleValidator(const string& doubleString);
};

#endif //FINAL_PROJECT_AIRQUALITYANALYZER_H

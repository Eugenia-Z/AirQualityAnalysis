#ifndef FINAL_PROJECT_AIRQUALITYANALYZER_H
#define FINAL_PROJECT_AIRQUALITYANALYZER_H
#include "MonthlyData.h"
#include <string>

class AirQualityAnalyzer {
public:
    void runAnalysis(const std::string& fileName);
    MonthlyData* getMonths();
    int getNumMonths();
    void printAllAvg()const;
    void printAllMax()const;
    void printMonth(int i);

private:
    static const int NUM_MONTHS = 14;
    MonthlyData months[NUM_MONTHS];
    int monthsIndex = -1;
    void readCSV(const std::string& fileName);
    bool doubleValidator(const string& doubleString);
};

#endif //FINAL_PROJECT_AIRQUALITYANALYZER_H

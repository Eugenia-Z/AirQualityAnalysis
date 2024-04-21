#ifndef FINAL_PROJECT_AIRQUALITYANALYZER_H
#define FINAL_PROJECT_AIRQUALITYANALYZER_H
#include "MonthlyData.h"
#include "VectorLinkedList.h"

class AirQualityAnalyzer {
public:
    // Read input and store data
    void readCSV(const string& fileName);

    // Get and print data
    void printMonthAvgTemp() const;
    void printMonthAvgRH() const;
    void printMonthAvgAH() const;
    void printMonthMaxTemp() const;
    void printMonthMaxRH() const;
    void printMonthMaxAH() const;
    void displayMonthHigherThanAvgTemp() const;
    void displayMonthHigherThanAvgRH() const;
    void displayMonthHigherThanAvgAH() const;
    void displayDataAtDate() const;

    // Helpers dealing with user input
    MonthlyData* processInputMonth() const;
    Date processInputDate() const;
    Time processInputTime() const;

    // Print data (for test purpose)
    void printAllAvg() const;
    void printAllMax() const;
    void printMonth() const;

private:
    // MonthlyData stored in a vector
    VectorLinkedList<MonthlyData> monthDataCollection;

    // Private helper validating double value in input
    bool doubleValidator(const string& doubleString);
};

#endif //FINAL_PROJECT_AIRQUALITYANALYZER_H

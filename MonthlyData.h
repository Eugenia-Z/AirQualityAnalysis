#ifndef FINAL_PROJECT_MONTHLYDATA_H
#define FINAL_PROJECT_MONTHLYDATA_H
#include "VectorLinkedList.h"
#include "AirQuality.h"

/**
 * @class MonthlyData
 * @brief Manages monthly data for air quality.
 * This class represents monthly air quality data, including temperature, relative humidity, and absolute humidity.
 * It provides methods to add data, calculate statistics, and display information.
 */
class MonthlyData {
public:
    // Constructor and destructor
    MonthlyData();
    ~MonthlyData() = default;

    // Getters and setters
    int getSize() const;
    Date getMonth() const;
    string getMonthString() const;
    double getMaxTemp() const;
    double getMaxRH() const;
    double getMaxAH() const;
    double getAvgTemp() const;
    double getAvgRH() const;
    double getAvgAH() const;
    void setMonth(const Date &d);

    // Methods
    bool isEmpty() const;
    void push(const AirQuality &a);

    // Display and print methods
    void print() const;
    void printSummary() const;
    void displayDataAt(const Date &date, const Time &time) const;
    void displayHigherThanAvgTemp() const;
    void displayHigherThanAvgRH() const;
    void displayHigherThanAvgAH() const;

private:
    VectorLinkedList<AirQuality> data;   // List of air quality data points
    Date thisMonth;  // The month of the data set
    double sumTemp;  // Sum of all valid temperatures of this month
    double sumRH;  // Sum of all valid relative humidity values of this month
    double sumAH;  // Sum of all valid absolute humidity values of this month
    double maxTemp;  // Maximum temperature of this month
    double maxRH;  // Maximum relative humidity of this month
    double maxAH;  // Maximum absolute humidity of this month
    int tempSize; // Number of valid temperature data points
    int RHSize;  // Number of valid relative humidity data points
    int AHSize;  // Number of valid absolute humidity data points
    int size;  // Total number of data points

    // Private helper functions
    VectorLinkedList<AirQuality> higherThanAvgTemp() const;
    VectorLinkedList<AirQuality> higherThanAvgRH() const;
    VectorLinkedList<AirQuality> higherThanAvgAH() const;
    AirQuality *search(const Date &date, const Time &time) const;
};

#endif // FINAL_PROJECT_MONTHLYDATA_H

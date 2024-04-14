#ifndef FINAL_PROJECT_MONTHLYDATA_H
#define FINAL_PROJECT_MONTHLYDATA_H
#include <string>
#include "Vector.h"
#include "AirQuality.h"
#include "Time.h"

class MonthlyData {
private:
    Vector<AirQuality> data;
    Date thisMonth;
    double sumTemp;
    double sumRH;
    double sumAH;
    double maxTemp;
    double maxRH;
    double maxAH;
    int size;

    // Private helper functions
    Vector<AirQuality> higherThanAvgTemp() const;
    Vector<AirQuality> higherThanAvgRH() const;
    Vector<AirQuality> higherThanAvgAH() const;
    void display(Vector<AirQuality>& v, const string& s) const;
    AirQuality* search(const Date& date, const Time& time) const;

public:
    // Constructor and destructor
    MonthlyData();
    ~MonthlyData();

    bool isEmpty() const;
    void push(const AirQuality& a);

    // Setters
    void setMonth(const Date& d);

    // Getters
    int getSize() const;
    Date getMonth() const;
    double getMaxTemp() const;
    double getMaxRH() const;
    double getMaxAH() const;
    double getAvgTemp() const;
    double getAvgRH() const;
    double getAvgAH() const;

    // Methods
    void displayHigherThanAvgTemp() const;
    void displayHigherThanAvgRH() const;
    void displayHigherThanAvgAH() const;
    void displayDataAt(const Date& date, const Time& time) const;
};


#endif //FINAL_PROJECT_MONTHLYDATA_H

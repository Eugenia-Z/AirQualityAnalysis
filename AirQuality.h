#include <iostream>
#include <string>
#include "Date.h"
#include "Time.h"

using namespace std;

#ifndef FINAL_PROJECT_AIRQUALITY_H
#define FINAL_PROJECT_AIRQUALITY_H

class AirQuality {
    // Overload operator <<
    friend ostream& operator<<(ostream&, const AirQuality&);

public:
    // Default constructor and destructor
    AirQuality() = default;
    ~AirQuality() = default;

    // Parameterized constructor
    AirQuality(const Date& d, const Time& t, double tmp, double rh, double ah);

    // Setters
    void setAirQuality(const Date& d, const Time& t, double tmp, double rh, double ah);
    void setDate(const Date& d);
    void setTime(const Time& t);

    // Getters
    Date getDate() const;
    Time getTime() const;
    double getTemp() const;
    double getRH() const;
    double getAH() const;

private:
    Date date; // Date
    Time time; // Time
    double temp; // Temperature
    double RH; // Relative humidity
    double AH; // Absolute humidity
};

#endif //FINAL_PROJECT_AIRQUALITY_H

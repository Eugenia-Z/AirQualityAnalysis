#include <iostream>
#include <iomanip>
#include "AirQuality.h"
#include "Date.h"
#include "Time.h"

using namespace std;

// Parameterized constructor
AirQuality::AirQuality(const Date& d, const Time& t, double tmp, double rh, double ah) {
    setAirQuality(d, t, tmp, rh, ah);
}

// Setters
void AirQuality::setAirQuality(const Date& d, const Time& t, double tmp, double rh, double ah) {
    setDate(d);
    setTime(t);
    temp = tmp;
    RH = rh;
    AH = ah;
}

void AirQuality::setDate(const Date& d) {
    date = d;
}

void AirQuality::setTime(const Time& t) {
    time = t;
}

// Getters
Date AirQuality::getDate() const {
    return date;
}

Time AirQuality::getTime() const {
    return time;
}

double AirQuality::getTemp() const {
    return temp;
}

double AirQuality::getRH() const {
    return RH;
}

double AirQuality::getAH() const {
    return AH;
}

// Overload operator <<
ostream& operator<<(ostream& os, const AirQuality& air) {
    os << air.getDate() << " " << air.getTime() << " "
       << "Temperature: " << fixed << setprecision(1) << air.getTemp()
       << " Relative Humidity: " << setprecision(1) << air.getRH()
       << " Absolute humidity: " << setprecision(4) << air.getAH() << endl;
    return os;
}

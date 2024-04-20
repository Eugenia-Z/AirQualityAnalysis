#include <iostream>
#include <string>
#include "Date.h"
#include "Time.h"
using namespace std;

#ifndef FINAL_PROJECT_AIRQUALITY_H
#define FINAL_PROJECT_AIRQUALITY_H

class AirQuality {
public:
    //default constructor
    AirQuality();

    //specific constructor
    AirQuality (Date d, Time t, double temperature, double relativeHumidity, double absoluteHumidity);

    //setters
    void setAirQuality (Date d, Time t, double temperature, double relativeHumidity, double absoluteHumidity);
    void setDate (Date d);
    void setTime (Time t);

    //getters
    AirQuality getAirQuality () const;
    Date getDate () const;
    Time getTime () const;
    double getTemp() const;
    double getRH() const;
    double getAH() const;

private:
    Date date; //date
    Time time; //time
    double temp; //temperature
    double RH; //relative humidity
    double AH; //absolute humidity
};

ostream & operator <<( ostream & os, const AirQuality & air );
//istream & operator >>( istream & input, Time & T );

#endif //FINAL_PROJECT_AIRQUALITY_H

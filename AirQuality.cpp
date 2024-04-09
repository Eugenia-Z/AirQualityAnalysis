#include <iostream>
#include <iomanip>
#include "AirQuality.h"
#include "Date.h"
#include "Time.h"

using namespace std;

//default constructor
AirQuality::AirQuality(){}

//specific constructor
AirQuality::AirQuality (Date d, Time ti, double temperature, double relativeHumidity, double absoluteHumidity){
    setAirQuality(d,ti, temperature, relativeHumidity, absoluteHumidity);
}

//setters
void AirQuality::setAirQuality (Date d, Time ti, double temperature, double relativeHumidity, double absoluteHumidity){
    setDate(d);
    setTime(ti);
    temp = temperature;
    RH = relativeHumidity;
    AH = absoluteHumidity;
}
void AirQuality::setDate (Date d){
    date = d;
}
void AirQuality::setTime (Time t){
    time = t;
}
//getters
AirQuality AirQuality::getAirQuality() const{
    return *this;
}
Date AirQuality::getDate () const{
    return date;
}
Time AirQuality::getTime () const{
    return time;
}
double AirQuality::getTemp() const{
    return temp;
}
double AirQuality::getRH() const{
    return RH;
}
double AirQuality::getAH() const{
    return AH;
}
ostream & operator <<( ostream & os, const AirQuality & air )
{
    os<<air.getDate()<<" " <<air.getTime()<<" "
      <<"Temperature: "<< fixed << setprecision(1) << air.getTemp()
      <<" Relative humidity: "<< setprecision(1)<< air.getRH()
      <<" Absolute humidity: "<< setprecision(4)<< air.getAH() << endl;
    return os;
}
// override cin and cout
//istream & operator >>( istream & input, AirQuality & air )
//{
//    string time,sHH;
//    int hh;
//
//    hh=stoi(sHH);
//
//    air.setAirQuality(hh);
//    return input;
//}
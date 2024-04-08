#include<iostream>
#include<string>
#include "Time.h"

using namespace std;

Time::Time()
{
    hour=0;
}
Time::Time(int hh)
{
    hour=hh;
}
Time::~Time()
{
    //none
}
int Time::getTime() const
{
    return hour;
}
void Time::setTime(int hh)
{
    hour=hh;
}
istream & operator >>( istream & input, Time & T )
{
    string time,sHH;
    int hh;

    hh=stoi(sHH);

    T.setTime(hh);
    return input;
}
ostream & operator <<( ostream & os, const Time & T )
{
    os<<"Time: "<<T.getTime()<<":00"<<":00";
    return os;
}
bool Time::operator==(const Time& otherTime) const {
    return hour == otherTime.hour;
}
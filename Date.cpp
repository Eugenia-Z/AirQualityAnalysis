#include "Date.h"
#include <string>
#include <iostream>

using namespace std;

Date::Date(){
    day=1;
    month=1;
    year=2000;
}
Date::Date(int dd, int mm, int yy){
    day=dd;
    month=mm;
    year=yy;
}
Date Date::getDate() const{
    return *this;
}
int Date::getDay() const{
    return day;
}
void Date::setDate(int dd, int mm, int yy)
{
    day=dd;
    month=mm;
    year=yy;
}
void Date::setDay(int dd){
    day=dd;
}
int Date::getMonth() const{
    return month;
}
void Date::setMonth(int mm){
    month=mm;
}
int Date::getYear() const{
    return year;
}
void Date::setYear(int yy){
    year=yy;
}
bool Date::sameMonth(Date otherDay)const{
    return (month==otherDay.getMonth());
}
void Date::printDate()
{
    cout<<"Date:  " << day <<" "<< month<<" "<<year<<'\n';
}
istream & operator >> ( istream & input, Date & D )
{
    string stringdd, stringmm, stringyy;
    int dd,mm, yy;

    getline(input, stringdd, '/');
    getline(input, stringmm,'/');
    getline(input, stringyy,' ');

    dd=stoi(stringdd);
    mm=stoi(stringmm);
    yy=stoi(stringyy);

    D.setDate(dd, mm, yy);

    return input;
}

ostream & operator <<( ostream & os, const Date & D )
{
    os << "Date: " << D.getDay() << "/" << D.getMonth() << "/" <<D.getYear();
    return os;
}

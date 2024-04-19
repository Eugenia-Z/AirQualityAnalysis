#include "Date.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

Date::Date(){
    year=2000;
    month=1;
    day=1;
}
Date::Date(int yy, int mm, int dd){
    day=dd;
    month=mm;
    year=yy;
}
Date::Date(const string& dateStr) {
    istringstream iss(dateStr);
    char delimiter;
    iss >> year >> delimiter >> month >> delimiter >> day;
}
Date Date::getDate() const{
    return *this;
}
int Date::getDay() const{
    return day;
}
void Date::setDate(int yy, int mm, int dd)
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
    return (month==otherDay.getMonth() && year==otherDay.getYear());
}
void Date::printDate()
{
    cout<<"Date: " << day <<"/"<< month<<"/"<<year<<'\n';
}
bool Date::operator==(const Date& otherDate) const {
    return (day == otherDate.getDay() && month == otherDate.getMonth() && year == otherDate.getYear());
}
bool Date::operator<(const Date& otherDate)const{
    if((year<otherDate.year)||
       (year==otherDate.year && month<otherDate.month)||
       (year==otherDate.year && month==otherDate.month && day<otherDate.day))
    {
        return true;
    }else{
        return false;
    }
}
bool Date::operator>(const Date& otherDate)const{
    return !(*this<=otherDate);
}
bool Date::operator<=(const Date& otherDate)const{
    return(*this<otherDate||*this==otherDate);
}
bool Date::operator>=(const Date& otherDate)const{
    return !(*this<otherDate);
}
bool Date::operator!=(const Date& otherDate)const{
    return !(*this==otherDate);
}
istream & operator >> ( istream & input, Date & D )
{
    string stringyy, stringmm, stringdd;
    int yy,mm,dd;

    getline(input, stringyy, '/');
    getline(input, stringmm,'/');
    getline(input, stringdd);

    dd=stoi(stringdd);
    mm=stoi(stringmm);
    yy=stoi(stringyy);

    D.setDate(yy, mm, dd);

    return input;
}
ostream & operator <<( ostream & os, const Date & D )
{
    os << D.getYear()<< "/" << D.getMonth() << "/" <<D.getDay();
    return os;
}

#ifndef FINAL_PROJECT_DATE_H
#define FINAL_PROJECT_DATE_H
#include <iostream>
#include <string>
using namespace std;

class Date
{
public:
    Date();
    Date(int yy, int mm, int dd);
    Date(const string& dateStr);
    Date getDate() const;
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void setDate(int yy, int mm, int dd);
    void setDay(int dd);
    void setMonth(int mm);
    void setYear(int yy);

    bool sameMonth(Date otherDay)const;
    bool operator==(const Date& otherDate) const;
    bool operator<(const Date& otherDate)const;
    bool operator>(const Date& otherDate)const;
    bool operator<=(const Date& otherDate)const;
    bool operator>=(const Date& otherDate)const;
    bool operator!=(const Date& otherDate)const;

    void printDate();

private:
    int day;
    int month;
    int year;
};

ostream & operator <<( ostream & os, const Date & D );
istream & operator >>( istream & input, Date & D );

#endif //FINAL_PROJECT_DATE_H

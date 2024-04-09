#ifndef FINAL_PROJECT_DATE_H
#define FINAL_PROJECT_DATE_H
#include <iostream>
#include <string>
using namespace std;

class Date
{
public:
    Date();
    Date(int dd, int mm, int yy);
    Date getDate() const;
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void setDate(int dd, int mm, int yy);
    void setDay(int dd);
    void setMonth(int mm);
    void setYear(int yy);

    bool sameMonth(Date otherDay)const;

    void printDate();

private:
    int day;
    int month;
    int year;
};

ostream & operator <<( ostream & os, const Date & D );
istream & operator >>( istream & input, Date & D );

#endif //FINAL_PROJECT_DATE_H

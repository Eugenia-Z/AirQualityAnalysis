#ifndef FINAL_PROJECT_TIME_H
#define FINAL_PROJECT_TIME_H

#include <iostream>
#include <string>

using namespace std;

class Time{
public:
    Time();
    Time(int hh, int mm, int ss);
    Time(const string& timeStr);
    virtual ~Time();
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    void setHour(int hh);
    void setMinute(int mm);
    void setSecond(int ss);
    void setTime(int hh, int mm, int ss);
    bool operator==(const Time& otherTime) const;
    bool operator<(const Time& otherTime)const;
    bool operator>(const Time& otherTime)const;

private:
    int hour;
    int minute;
    int second;
};
ostream & operator <<( ostream & os, const Time & T );
istream & operator >>( istream & input, Time & T );

#endif //FINAL_PROJECT_TIME_H

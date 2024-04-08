#ifndef FINAL_PROJECT_TIME_H
#define FINAL_PROJECT_TIME_H

#include <iostream>
#include <string>

using namespace std;

class Time{
public:
    Time();
    Time(int hh);
    virtual ~Time();

    void setTime(int hh);
    int getTime() const;
    bool operator==(const Time& otherTime) const;

private:
    int hour;
};
ostream & operator <<( ostream & os, const Time & T );
istream & operator >>( istream & input, Time & T );

#endif //FINAL_PROJECT_TIME_H

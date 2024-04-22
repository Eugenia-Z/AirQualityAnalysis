#ifndef FINAL_PROJECT_TIME_H
#define FINAL_PROJECT_TIME_H
#include <iostream>
#include <string>

using namespace std;

class Time {
    // Overload << and >> operators
    friend ostream& operator<<(ostream&, const Time&);
    friend istream& operator>>(istream&, Time&);

public:
    // Constructors and destructor
    Time();
    Time(int hh, int mm, int ss);
    Time(const string& timeStr);
    ~Time() = default;

    // Getters and Setters
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    void setHour(int hh);
    void setMinute(int mm);
    void setSecond(int ss);
    void setTime(int hh, int mm, int ss);

    // Overload relational operators
    bool operator==(const Time& otherTime) const;
    bool operator<(const Time& otherTime) const;
    bool operator>(const Time& otherTime) const;

private:
    int hour;
    int minute;
    int second;
};

#endif //FINAL_PROJECT_TIME_H

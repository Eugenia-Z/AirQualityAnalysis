#ifndef FINAL_PROJECT_DATE_H
#define FINAL_PROJECT_DATE_H
#include <iostream>
#include <string>

using namespace std;

class Date {
    // Overload << and >> operators
    friend ostream& operator<<(ostream&, const Date&);
    friend istream& operator>>(istream&, Date&);

public:
    // Constructors and destructor
    Date();
    Date(int yy, int mm, int dd);
    Date(const string& dateStr);
    ~Date() = default;

    // Getters and setters
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void setDate(int yy, int mm, int dd);
    void setDay(int dd);
    void setMonth(int mm);
    void setYear(int yy);

    // Methods
    bool sameMonth(Date otherDay)const;
    void printDate() const;

    // Overload relational operators
    bool operator==(const Date& otherDate) const;
    bool operator<(const Date& otherDate)const;
    bool operator>(const Date& otherDate)const;
    bool operator<=(const Date& otherDate)const;
    bool operator>=(const Date& otherDate)const;
    bool operator!=(const Date& otherDate)const;

private:
    int day;
    int month;
    int year;
};

#endif //FINAL_PROJECT_DATE_H

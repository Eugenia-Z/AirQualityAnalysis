#include <iostream>
#include "Time.h"
#include "Date.h"
#include "AirQuality.h"
using namespace std;

int main()
{
    //----------------test Time class------------------
    // create instances
    Time t1;
    Time t2(11, 11, 11);
    Time t3(11, 11, 11);
    Time t4(22,00,00);

    // test cin and cout
    cout << "Enter time (hh:mm:ss): ";
    cin >> t1;
    cout << "Time entered: " << t1 << std::endl;

    // Testing the operator==()
    if (t2 == t3){
        cout << "t1 and t2 are equal." << std::endl;
    }else{
        cout << "t1 and t2 are not equal." << std::endl;
    }

    // testing the operator >
    if (t4 > t3){
        cout << "t4 is later than t3." << std::endl;
    }else{
        cout << "t4 is not later than t3." << std::endl;
    }

    // testing the operator <
    if (t4 < t3){
        cout << "t4 is not later than t3." << std::endl;
    }else{
        cout << "t4 is later than t3." << std::endl;
    }

    //----------------test Date class------------------
    Date d1(2004, 12, 31);
    Date d2(2004, 12, 18);
    Date d3(2004, 12, 2);
    Date d4(2004, 12, 2);
    Date d5;

    // Test setDay(), setMonth(), setYear() functions
    d1.setDay(10);
    d1.setMonth(4);
    d1.setYear(2004);
    std::cout << "Updated today's date: ";
    d1.printDate();

    // Test getDay(), getMonth(), getYear() functions
    cout << "Day: " << d1.getDay() << endl;
    cout << "Month: " << d1.getMonth() << endl;
    cout << "Year: " << d1.getYear() << endl;

    // Test sameMonth() function
    if (d2.sameMonth(d3))
    {
        cout << "d2 is in the same month as d3. \n";
    }
    if (!d1.sameMonth(d3))
    {
        cout << "d1 is NOT in the same month as d3. \n";
    }

    // Test operator==() function
    if (d3 == d4)
    {
        cout << "d3 and d4 is the same day.\n";
    }

    // Test comparison
    if(d2>d3){
        cout << "d2 is later than d3"<< endl;
    }else{
        cout << "d2 is not later than d3"<< endl;
    }
    if(d3<d2){
        cout << "d3 is earlier than d2"<< endl;
    }else{
        cout << "d3 is not earlier than d2"<< endl;
    }

    // Test operator<< and operator>> functions
    cout << "Enter a date (yyyy/mm/dd): ";
    cin >> d5;
    cout << "Entered date: " << d5 << endl;
    cout << d1 << endl;

    //--------------------test AirQuality class------------------
    AirQuality air1(d1, t1, 13.6, 48.9, 0.7578);
    AirQuality air2(d2, t2, 11.0, 50.0, 0.7000);
    cout << air1;
    cout << air2;

    return 0;
}

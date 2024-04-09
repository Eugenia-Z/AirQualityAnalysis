#include <iostream>
#include "Time.h"
#include "Date.h"
#include "AirQuality.h"
using namespace std;

int main() {
    Time t1(12);
    Time t2(11);
    Time t3(12);
    cout << t1 << endl;
    cout << (t1==t2) << endl;
    cout << (t1==t3) << endl;

    Date d1(31,12,2004);
    Date d2(31,11,2004);
    Date d3(2,12,2004);
    cout << d1 << endl;
    cout << (d1.sameMonth(d2)) << endl;
    cout << (d1.sameMonth(d3)) << endl;

    AirQuality air1(d1, t1, 13.6, 48.9, 0.7578);
    AirQuality air2(d2, t2, 11.0, 50.0, 0.7000);
    cout << air1;
    cout << air2;

    return 0;
}

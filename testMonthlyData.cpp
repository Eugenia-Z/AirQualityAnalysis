#include <iostream>
#include <vector>
#include "AirQuality.h"
#include "Date.h"
#include "MonthlyData.h"
#include "Time.h"


using namespace std;

int main() {
    // Test constructor, isEmpty() and getSize()
    MonthlyData thisMonth;
    cout << "Empty: " << thisMonth.isEmpty() << endl;
    cout << "size: " << thisMonth.getSize() << endl;
    thisMonth.displayHigherThanAvgTemp();

    AirQuality aq0(Date(2004, 12, 31), Time(12, 0, 0),
                   25.5, 60.0, 0.044);
    AirQuality aq1(Date(2004, 12, 18), Time(11, 0, 0),
                   25.4, 60.1, 0.045);
    AirQuality aq2(Date(2004, 12, 2), Time(14, 0, 0),
                   26.2, 58.5, 0.042);

    cout << "Testing push()" << endl;
    thisMonth.push(AirQuality());
    thisMonth.push(aq0);
    thisMonth.push(aq1);
    thisMonth.push(aq2);

    cout << "Testing setMonth()" << endl;
    thisMonth.setMonth(aq0.getDate());

    cout << "Testing getMonth() and getMonthString" << endl;
    cout << thisMonth.getMonth() << endl;
    cout << thisMonth.getMonthString() << endl;

    cout << "Testing get average value methods" << endl;
    cout << thisMonth.getAvgTemp() << endl;
    cout << thisMonth.getAvgRH() << endl;
    cout << thisMonth.getAvgAH() << endl;

    cout << "Testing get max value methods" << endl;
    cout << thisMonth.getMaxTemp() << endl;
    cout << thisMonth.getMaxRH() << endl;
    cout << thisMonth.getMaxAH() << endl;

    cout << "Testing display methods" << endl;
    thisMonth.displayHigherThanAvgTemp();
    thisMonth.displayHigherThanAvgRH();
    thisMonth.displayHigherThanAvgAH();
    thisMonth.displayDataAt(Date(0,12,2004), Time (0,0,0));
    thisMonth.displayDataAt(Date(2004, 12, 2), Time(14, 0, 0));
    thisMonth.displayDataAt(Date(2004, 12, 2), Time(14, 0, 0));


    cout << "Testing printSummary()" << endl;
    thisMonth.printSummary();

    cout << "Testing print()" << endl;
    thisMonth.print();

    return 0;
}
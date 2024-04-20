#include <iostream>
#include <vector>
#include "AirQuality.h"
#include "Date.h"
#include "MonthlyData.h"
#include "Time.h"
#include "AirQualityAnalyzer.h"

using namespace std;

int main() {
    MonthlyData thisMonth;
    AirQualityAnalyzer analyzer;

    cout << thisMonth.isEmpty() << endl;
    thisMonth.printSummary();
    thisMonth.displayDataAt(Date(12,12,2004), Time (12,0,0));

    return 0;
}
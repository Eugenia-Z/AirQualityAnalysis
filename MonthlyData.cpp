#include "MonthlyData.h"

/* Construct an empty MonthlyData instance.*/
MonthlyData::MonthlyData() {
    size = 0;
    tempSize = 0;
    RHSize = 0;
    AHSize = 0;
    sumTemp = 0;
    sumRH = 0;
    sumAH = 0;
    maxTemp = 0;
    maxRH = 0;
    maxAH = 0;
    thisMonth = Date(0, 0, 0);
}

/* Check if the MonthlyData is empty.*/
bool MonthlyData::isEmpty() const {
    return size == 0;
}

/**
 * Add a new air quality data point to the data set
 * Update all relevant the statistics at the same time
 */
void MonthlyData::push(const AirQuality &a) {
    data.push_back(a);
    size++;
    sumTemp += a.getTemp();
    tempSize += a.getTemp() == 0.0 ? 0 : 1;
    sumRH += a.getRH();
    RHSize += a.getRH() == 0.0 ? 0 : 1;
    sumAH += a.getAH();
    AHSize += a.getAH() == 0.0 ? 0 : 1;
    maxTemp = maxTemp > a.getTemp() ? maxTemp : a.getTemp();
    maxRH = maxRH > a.getRH() ? maxRH : a.getRH();
    maxAH = maxAH > a.getAH() ? maxAH : a.getAH();
}

void MonthlyData::setMonth(const Date &date) {
    thisMonth = date;
}

int MonthlyData::getSize() const {
    return size;
}

Date MonthlyData::getMonth() const {
    return thisMonth;
}

string MonthlyData::getMonthString() const {
    string s = to_string(thisMonth.getYear()) + "/" + to_string(thisMonth.getMonth());
    return s;
}

double MonthlyData::getAvgTemp() const {
    return tempSize == 0 ? 0.0 : sumTemp / tempSize;
}

double MonthlyData::getAvgRH() const {
    return RHSize == 0 ? 0.0 : sumRH / RHSize;
}

double MonthlyData::getAvgAH() const {
    return AHSize == 0 ? 0.0 : sumAH / AHSize;
}

double MonthlyData::getMaxTemp() const {
    return maxTemp;
}

double MonthlyData::getMaxRH() const {
    return maxRH;
}

double MonthlyData::getMaxAH() const {
    return maxAH;
}

/* Prints all air quality data in the data set. */
void MonthlyData::print() const {
    for (auto &a : data)
        cout << a;
}

/* Print a summary of statistics for this month. */
void MonthlyData::printSummary() const {
    cout << endl;
    cout << size << " data found for " << getMonthString() << endl;
    cout << "__________________________________" << endl;
    cout << tempSize << " valid temperature data" << endl;
    cout << "Average Temperature: " << getAvgTemp() << endl;
    cout << "Maximum Temperature: " << getMaxTemp() << endl;
    cout << "__________________________________" << endl;
    cout << RHSize << " valid relative humidity data" << endl;
    cout << "Average Relative Humidity: " << getAvgRH() << endl;
    cout << "Maximum Relative Humidity: " << getMaxRH() << endl;
    cout << "__________________________________" << endl;
    cout << AHSize << " valid absolute humidity data" << endl;
    cout << "Average Absolute Humidity: " << getAvgAH() << endl;
    cout << "Maximum Absolute Humidity: " << getMaxAH() << endl;
}

/* Display data at a specific date and time. */
void MonthlyData::displayDataAt(const Date &date, const Time &time) const {
    AirQuality *airQuality = search(date, time);
    if (airQuality == nullptr)
        cout << "Data not found" << endl; // Print an error message if no matched data found
    else
        cout << *airQuality;
}

/* Display data points with temperature higher than the average. */
void MonthlyData::displayHigherThanAvgTemp() const {
    VectorLinkedList<AirQuality> v = higherThanAvgTemp();
    if (!v.empty()) {
        cout << "Dates and times when the temperature"
             << " is higher than the average:" << endl;
        for (auto &aq : v)
            cout << aq.getDate() << " " << aq.getTime() << " " << aq.getTemp() << endl;
    } else {
        cout << "No valid data found for this month" << endl;
    }
}

/* Display data points with relative humidity higher than the average. */
void MonthlyData::displayHigherThanAvgRH() const {
    VectorLinkedList<AirQuality> v = higherThanAvgRH();
    if (!v.empty()) {
        cout << "Dates and times when the relative humidity"
             << " is higher than the average:" << endl;
        for (auto &aq : v)
            cout << aq.getDate() << " " << aq.getTime() << " " << aq.getRH() << endl;
    } else {
        cout << "No valid data found for this month" << endl;
    }
}

/* Display data points with absolute humidity higher than the average. */
void MonthlyData::displayHigherThanAvgAH() const {
    VectorLinkedList<AirQuality> v = higherThanAvgAH();
    if (!v.empty()) {
        cout << "Dates and times when the absolute humidity"
             << " is higher than the average:" << endl;
        for (auto &aq : v)
            cout << aq.getDate() << " " << aq.getTime() << " " << aq.getAH() << endl;
    } else {
        cout << "No valid data found for this month" << endl;
    }
}

/* Search for air quality data given a specific date and time. */
AirQuality *MonthlyData::search(const Date &date, const Time &time) const {
    AirQuality *airQuality = nullptr;
    for (auto &aq : data) {
        if (aq.getDate() == date && aq.getTime() == time)
            airQuality = &aq;
    }
    return airQuality;
}

/* Retrieve data points with temperatures higher than the average. */
VectorLinkedList<AirQuality> MonthlyData::higherThanAvgTemp() const {
    VectorLinkedList<AirQuality> higher;
    double avgT = getAvgTemp();
    for (auto &it : data) {
        cout << "this step" << endl;
        if (it.getTemp() > avgT)
            higher.push_back(it);
    }
    return higher;
}

/* Retrieve data points with relative humidity higher than the average. */
VectorLinkedList<AirQuality> MonthlyData::higherThanAvgRH() const {
    VectorLinkedList<AirQuality> higher;
    double avgRH = getAvgRH();
    for (auto &it : data) {
        if (it.getRH() > avgRH)
            higher.push_back(it);
    }
    return higher;
}

/* Retrieve data points with absolute humidity higher than the average. */
VectorLinkedList<AirQuality> MonthlyData::higherThanAvgAH() const {
    VectorLinkedList<AirQuality> higher;
    double avgAH = getAvgAH();
    for (auto &it : data) {
        if (it.getAH() > avgAH)
            higher.push_back(it);
    }
    return higher;
}

#include "MonthlyData.h"

MonthlyData::MonthlyData() = default;

MonthlyData::~MonthlyData() = default;

bool MonthlyData::isEmpty() const
{
    return size == 0;
}

void MonthlyData::push(const AirQuality &a)
{
    data.push_back(a);
    size++;
    sumTemp += a.getTemp();
    sumRH += a.getRH();
    sumAH += a.getAH();
    maxTemp = maxTemp > a.getTemp() ? maxTemp : a.getTemp();
    maxRH = maxRH > a.getRH() ? maxRH : a.getRH();
    maxAH = maxAH > a.getAH() ? maxAH : a.getAH();
}

void MonthlyData::setMonth(const Date &d)
{
    thisMonth = d;
}

int MonthlyData::getSize() const
{
    return size;
}

Date MonthlyData::getMonth() const
{
    return thisMonth;
}

double MonthlyData::getAvgTemp() const
{
    return sumTemp / size;
    //    if (!isEmpty() && sumTemp == 0) {
    //        double total = 0;
    //        VectorLinkedList<AirQuality>::Iterator it;
    //        for (it = data.begin(); it != data.end(); ++it) {
    //            total += (*it).getTemp();
    //        }
    //        sumTemp = total / size;
    //    }
    //    return abgTemp;
}

double MonthlyData::getAvgRH() const
{
    return sumRH / size;
    //    if (!isEmpty() && avgRH == 0) {
    //        double total = 0;
    //        VectorLinkedList<AirQuality>::Iterator it;
    //        for (it = data.begin(); it != data.end(); ++it) {
    //            total += (*it).getRH();
    //        }
    //        avgRH = total / size;
    //    }
    //    return avgRH;
}

double MonthlyData::getAvgAH() const
{
    return sumAH / size;
    //    if (!isEmpty() && avgAH == 0) {
    //        double total = 0;
    //        VectorLinkedList<AirQuality>::Iterator it;
    //        for (it = data.begin(); it != data.end(); ++it) {
    //            total += (*it).getAH();
    //        }
    //        avgAH = total / size;
    //    }
    //    return avgAH;
}

double MonthlyData::getMaxTemp() const
{
    return maxTemp;
    //    if (!isEmpty() && maxTemp == 0) {
    //        double tmp = 0;
    //        VectorLinkedList<AirQuality>::Iterator it;
    //        for (it = data.begin(); it != data.end(); ++it) {
    //            if ((*it).getTemp() > tmp)
    //                tmp = (*it).getTemp();
    //        }
    //        maxTemp = tmp;
    //    }
    //    return maxTemp;
}

double MonthlyData::getMaxRH() const
{
    return maxRH;
    //    if (!isEmpty() && maxRH == 0) {
    //        double tmp = 0;
    //        VectorLinkedList<AirQuality>::Iterator it;
    //        for (it = data.begin(); it != data.end(); ++it) {
    //            if ((*it).getRH() > tmp)
    //                tmp = (*it).getRH();
    //        }
    //        maxRH = tmp;
    //    }
    //    return maxRH;
}

double MonthlyData::getMaxAH() const
{
    return maxAH;
    //    if (!isEmpty() && maxAH == 0) {
    //        double tmp = 0;
    //        VectorLinkedList<AirQuality>::Iterator it;
    //        for (it = data.begin(); it != data.end(); ++it) {
    //            if ((*it).getAH() > tmp)
    //                tmp = (*it).getAH();
    //        }
    //        maxAH = tmp;
    //    }
    //    return maxAH;
}

AirQuality *MonthlyData::search(const Date &date, const Time &time) const
{
    AirQuality *air = nullptr;
    for (VectorLinkedList<AirQuality>::Iterator it = data.begin(); it != data.end(); ++it)
    {
        if ((*it).getDate() == date && (*it).getTime() == time)
        {
            air = &(*it);
        }
    }
    //    if (air == nullptr) {
    //        cout << "Date and time not found" << endl;
    //    }
    return air;
}
void MonthlyData::displayDataAt(const Date &date, const Time &time) const
{
    AirQuality *a = search(date, time);
    if (a == nullptr)
    {
        cout << "Data for the date and time not found" << endl;
    }
    else
    {
        cout << "Temperature: " << a->getTemp() << endl;
        cout << "Relative Humidity: " << a->getRH() << endl;
        cout << "Absolute Humidity: " << a->getAH() << endl;
    }
}

void MonthlyData::displayHigherThanAvgTemp() const
{
    VectorLinkedList<AirQuality> v = higherThanAvgTemp();
    display(v, "temperature");
}

void MonthlyData::displayHigherThanAvgRH() const
{
    VectorLinkedList<AirQuality> v = higherThanAvgRH();
    display(v, "relative humidity");
}

void MonthlyData::displayHigherThanAvgAH() const
{
    VectorLinkedList<AirQuality> v = higherThanAvgAH();
    display(v, "absolute humidity");
}

VectorLinkedList<AirQuality> MonthlyData::higherThanAvgTemp() const
{
    VectorLinkedList<AirQuality> higher;
    double avgT = getAvgTemp();
    for (VectorLinkedList<AirQuality>::Iterator it = data.begin(); it != data.end(); ++it)
    {
        if ((*it).getTemp() > avgT)
        {
            higher.push_back(*it);
        }
    }
    return higher;
}

VectorLinkedList<AirQuality> MonthlyData::higherThanAvgRH() const
{
    VectorLinkedList<AirQuality> higher;
    double avgRH = getAvgRH();
    for (VectorLinkedList<AirQuality>::Iterator it = data.begin(); it != data.end(); ++it)
    {
        if ((*it).getRH() > avgRH)
        {
            higher.push_back(*it);
        }
    }
    return higher;
}

VectorLinkedList<AirQuality> MonthlyData::higherThanAvgAH() const
{
    VectorLinkedList<AirQuality> higher;
    double avgAH = getAvgAH();
    for (VectorLinkedList<AirQuality>::Iterator it = data.begin(); it != data.end(); ++it)
    {
        if ((*it).getAH() > avgAH)
        {
            higher.push_back(*it);
        }
    }
    return higher;
}

void MonthlyData::display(VectorLinkedList<AirQuality> &v, const string &s) const
{
    cout << "In this month,  dates and times when the " << s
         << " is higher than the average " << s << " as follows: " << endl;
    for (VectorLinkedList<AirQuality>::Iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << (*it).getDate() << " " << (*it).getTime() << endl;
    }
}

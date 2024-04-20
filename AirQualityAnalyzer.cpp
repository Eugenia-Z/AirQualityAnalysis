#include "AirQualityAnalyzer.h"
#include "AirQualityAnalyzer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

// read input
void AirQualityAnalyzer::readCSV(const std::string &fileName)
{
    ifstream inFile;
    string line;
    inFile.open(fileName);

    if (!inFile)
    {
        cout << "fail to open the file" << endl;
    }
    getline(inFile, line);

    while (getline(inFile, line))
    {
        // stop read CSV when get a line start with ","
        if (line[0] == ',')
        {
            break;
        }
        stringstream ss(line);
        string dateString, timeString, temperatureString, rhString, ahString;
        double temperature, rh, ah;

        getline(ss, dateString, ',');
        Date date(dateString);

        getline(ss, timeString, ',');
        Time time(timeString);

        for (int i = 0; i < 10; ++i)
        {
            ss.ignore(numeric_limits<streamsize>::max(), ',');
        }

        getline(ss, temperatureString, ',');
        if (doubleValidator(temperatureString) && stod(temperatureString) > -199)
        {
            temperature = stod(temperatureString);
        }
        else
        {
            temperature = NULL;
        }

        getline(ss, rhString, ',');
        if (doubleValidator(rhString) && stod(rhString) > -199)
        {
            rh = stod(rhString);
        }
        else
        {
            rh = NULL;
        }

        getline(ss, ahString, ',');
        if (doubleValidator(ahString) && stod(ahString) > -199)
        {
            ah = stod(ahString);
        }
        else
        {
            ah = NULL;
        }
        AirQuality air(date, time, temperature, rh, ah);

        // store the data into MonthlyData instance
        if (monthsIndex >= 0 && months[monthsIndex].getMonth().sameMonth(date))
        { // if the date belongs to this month, store it to the month
            months[monthsIndex].push(air);
        }
        else
        { // if the date does not belong to current month
            months[++monthsIndex].setMonth(date);
            months[monthsIndex].push(air);
        }
    }
    inFile.close();
}
// validate double value in input
bool AirQualityAnalyzer::doubleValidator(const string &doubleString)
{
    stringstream ss(doubleString);
    double value;
    ss >> value;
    if (ss.fail() || ss.peek() != EOF)
    {
        return false;
    }
    return true;
}
// get and print data of all the average
void AirQualityAnalyzer::printAllAvg() const
{
    cout << "------------avg temperature------------" << endl;
    for (int i = 0; i < NUM_MONTHS; i++)
    {
        cout << i << " month: " << fixed << setprecision(2) << months[i].getAvgTemp() << endl;
    }
    cout << "------------avg rh------------" << endl;
    for (int i = 0; i < NUM_MONTHS; i++)
    {
        cout << i << " month: " << fixed << setprecision(2) << months[i].getAvgRH() << endl;
    }
    cout << "------------avg ah------------" << endl;
    for (int i = 0; i < NUM_MONTHS; i++)
    {
        cout << i << " month: " << fixed << setprecision(2) << months[i].getAvgAH() << endl;
    }
}
// get and print data of all the max
void AirQualityAnalyzer::printAllMax() const
{
    cout << "------------max temperature------------" << endl;
    for (int i = 0; i < NUM_MONTHS; i++)
    {
        cout << i << " month: " << fixed << setprecision(2) << months[i].getMaxTemp() << endl;
    }
    cout << "------------max rh------------" << endl;
    for (int i = 0; i < NUM_MONTHS; i++)
    {
        cout << i << " month: " << fixed << setprecision(2) << months[i].getMaxRH() << endl;
    }
    cout << "------------max ah------------" << endl;
    for (int i = 0; i < NUM_MONTHS; i++)
    {
        cout << i << " month: " << fixed << setprecision(2) << months[i].getMaxAH() << endl;
    }
}
// get and print data of a month
void AirQualityAnalyzer::printMonth(int i)
{
    if (i >= NUM_MONTHS)
    {
        throw "month index out of range";
    }
    cout << "------------monthly data ------------" << endl;
    months[i].print();
}
// deal with user input
int AirQualityAnalyzer::processInputMonth()
{
    string input;
    cout << "Please enter the month (yyyy/mm): ";
    cin >> input;
    string month_input = input + "/1";

    istringstream iss(month_input);
    int year, month, day;
    char delimiter;
    iss >> year >> delimiter >> month >> delimiter >> day;
    Date findDay(year, month, day);

    cout << "Loading data for " << findDay.getYear() << "/" << findDay.getMonth() << endl;

    int i;
    for (i = 0; i < NUM_MONTHS; i++)
    {
        if (months[i].getMonth().sameMonth(findDay))
        {
            return i;
        }
    }
    cin.ignore();
    return -1;
}
// deal with input a date
Date AirQualityAnalyzer::processInputDate()
{
    Date findDay;
    cout << "Please enter the date (yyyy/mm/dd):";
    cin >> findDay;
    return findDay;
}
// deal with input a time
Time AirQualityAnalyzer::processInputTime()
{
    Time findTime;
    cout << "Please enter the time (hh:mm:ss):";
    cin >> findTime;
    return findTime;
}
// get and print data
double AirQualityAnalyzer::getMonthAvgTemp(int index)
{
    return months[index].getAvgTemp();
}
double AirQualityAnalyzer::getMonthAvgRH(int index)
{
    return months[index].getAvgRH();
}
double AirQualityAnalyzer::getMonthAvgAH(int index)
{
    return months[index].getAvgAH();
}
double AirQualityAnalyzer::getMonthMaxTemp(int index)
{
    return months[index].getMaxTemp();
}
double AirQualityAnalyzer::getMonthMaxRH(int index)
{
    return months[index].getMaxRH();
}
double AirQualityAnalyzer::getMonthMaxAH(int index)
{
    return months[index].getMaxAH();
}
void AirQualityAnalyzer::displayMonthHigherThanAvgTemp(int index)
{
    months[index].displayHigherThanAvgTemp();
}
void AirQualityAnalyzer::displayMonthHigherThanAvgRH(int index)
{
    months[index].displayHigherThanAvgRH();
}
void AirQualityAnalyzer::displayMonthHigherThanAvgAH(int index)
{
    months[index].displayHigherThanAvgAH();
}
void AirQualityAnalyzer::displayDataAtDate()
{
    Date date = processInputDate();
    int i;
    for (i = 0; i < NUM_MONTHS; i++)
    {
        if (months[i].getMonth().sameMonth(date))
        {
            Time time = processInputTime();
            time.setMinute(0);
            time.setSecond(0);
            cout << "Loading data for " << date << " " << time << endl;
            months[i].displayDataAt(date, time);
            break;
        }
    }
    if (i == NUM_MONTHS)
    {
        cout << "Input Date and Time Invalid." << endl;
    }
}
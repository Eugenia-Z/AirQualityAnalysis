#include "AirQualityAnalyzer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

// Read input and store data
void AirQualityAnalyzer::readCSV(const std::string &fileName) {
    ifstream inFile;
    string line;
    inFile.open(fileName);

    if (!inFile)
        cout << "fail to open the file" << endl;
    getline(inFile, line);

    while (getline(inFile, line)) {
        // Stop read CSV when get a line start with ","
        if (line[0] == ',')
            break;

        stringstream ss(line);
        string dateString, timeString, temperatureString, rhString, ahString;
        double temperature, rh, ah;

        getline(ss, dateString, ',');
        Date date(dateString);

        getline(ss, timeString, ',');
        Time time(timeString);

        for (int i = 0; i < 10; ++i)
            ss.ignore(numeric_limits<streamsize>::max(), ',');


        getline(ss, temperatureString, ',');
        if (doubleValidator(temperatureString) && stod(temperatureString) > 0)
            temperature = stod(temperatureString);
        else
            temperature = 0.0;

        getline(ss, rhString, ',');
        if (doubleValidator(rhString) && stod(rhString) > 0)
            rh = stod(rhString);
        else
            rh = 0.0;

        getline(ss, ahString, ',');
        if (doubleValidator(ahString) && stod(ahString) > 0)
            ah = stod(ahString);
        else
            ah = 0.0;

        AirQuality air(date, time, temperature, rh, ah);
        // Store the data into MonthlyData instance
        if (!monthDataCollection.empty() && monthDataCollection[monthDataCollection.getSize() - 1].getMonth().sameMonth(date)) {
            monthDataCollection[monthDataCollection.getSize() - 1].push(air);
        } else {
            // if the date does not belong to current month
            monthDataCollection.push_back(MonthlyData());
            monthDataCollection[monthDataCollection.getSize() - 1].push(air);
            monthDataCollection[monthDataCollection.getSize() - 1].setMonth(date);
        }
    }
    inFile.close();
}

// Get and print data
void AirQualityAnalyzer::printMonthAvgTemp() const {
    cout << "You are trying to know the average temperature for a month. \n";
    MonthlyData* targetMonth = processInputMonth();
    if (targetMonth == nullptr)
        cout << "Input month is out of range." << endl;
    else
        cout << "The average temperature for this month: " << fixed
             << setprecision(2) << targetMonth->getAvgTemp() << endl;
}

void AirQualityAnalyzer::printMonthAvgRH() const {
    cout << "You are trying to know the average relative humidity for a month. \n";
    MonthlyData* targetMonth = processInputMonth();
    if (targetMonth == nullptr)
        cout << "Input month is out of range." << endl;
    else
        cout << "The average relative humidity for this month: " << fixed
             << setprecision(2) << targetMonth->getAvgRH() << endl;
}

void AirQualityAnalyzer::printMonthAvgAH() const {
    cout << "You are trying to know the average absolute humidity for a month. \n";
    MonthlyData* targetMonth = processInputMonth();
    if (targetMonth == nullptr)
        cout << "Input month is out of range." << endl;
    else
        cout << "The average absolute humidity for this month: " << fixed
             << setprecision(2) << targetMonth->getAvgAH() << endl;
}

void AirQualityAnalyzer::printMonthMaxTemp() const {
    cout << "You are trying to know the highest temperature for a month. \n";
    MonthlyData* targetMonth = processInputMonth();
    if (targetMonth == nullptr)
        cout << "Input month is out of range." << endl;
    else
        cout << "The highest temperature for this month: " << fixed
             << setprecision(2) << targetMonth->getMaxTemp() << endl;
}

void AirQualityAnalyzer::printMonthMaxRH() const {
    cout << "You are trying to know the highest relative humidity for a month. \n";
    MonthlyData* targetMonth = processInputMonth();
    if (targetMonth == nullptr)
        cout << "Input month is out of range." << endl;
    else
        cout << "The highest relative humidity for this month: " << fixed
             << setprecision(2) << targetMonth->getMaxRH() << endl;
}

void AirQualityAnalyzer::printMonthMaxAH() const {
    cout << "You are trying to know the highest absolute humidity for a month. \n";
    MonthlyData* targetMonth = processInputMonth();
    if (targetMonth == nullptr)
        cout << "Input month is out of range." << endl;
    else
        cout << "The highest absolute humidity for this month: " << fixed
             << setprecision(2) << targetMonth->getMaxAH() << endl;
}

void AirQualityAnalyzer::displayMonthHigherThanAvgTemp() const {
    cout << "You are trying to know the dates and times for a month when the temperature is higher than the average. \n";
    MonthlyData* targetMonth = processInputMonth();
    if (targetMonth == nullptr)
        cout << "Input month is out of range." << endl;
    else
        targetMonth->displayHigherThanAvgTemp();
}

void AirQualityAnalyzer::displayMonthHigherThanAvgRH() const {
    cout << "You are trying to know the dates and times for a month when the relative humidity is higher than the average.\n";
    MonthlyData* targetMonth = processInputMonth();
    if (targetMonth == nullptr)
        cout << "Input month is out of range." << endl;
    else
        targetMonth->displayHigherThanAvgRH();
}

void AirQualityAnalyzer::displayMonthHigherThanAvgAH() const {
    cout << "You are trying to know the dates and times for a month when the absolute humidity is higher than the average.\n";
    MonthlyData* targetMonth = processInputMonth();
    if (targetMonth == nullptr)
        cout << "Input month is out of range." << endl;
    else
        targetMonth->displayHigherThanAvgAH();
}

void AirQualityAnalyzer::displayDataAtDate() const {
    cout << "You are trying to know the air quality data at the specific time of a day." << endl;
    Date date = processInputDate();
    for (auto &it : monthDataCollection) {
        if (it.getMonth().sameMonth(date)) {
            Time time = processInputTime();
            time.setMinute(0);
            time.setSecond(0);
            cout << "Loading data for " << date << " " << time << endl;
            it.displayDataAt(date, time);
            return;
        }
    }
    cout << "Input Date and Time Invalid." << endl;
}

// Deal with user input: month
MonthlyData* AirQualityAnalyzer::processInputMonth() const {
    string input;
    cout << "Please enter the month (yyyy/mm): ";
    cin >> input;
    string month_input = input + "/1";

    istringstream iss(month_input);
    int year, month, day;
    char delimiter;
    iss >> year >> delimiter >> month >> delimiter >> day;
    Date findDay(year, month, day);

    MonthlyData* target = nullptr;
    for (auto &m : monthDataCollection) {
        if (m.getMonth().sameMonth(findDay)) {
            cout << "Loading data for " << m.getMonthString() << endl;
            target = &m;
        }
    }
    return target;
}

// Deal with input: Date
Date AirQualityAnalyzer::processInputDate() const {
    Date findDay;
    cout << "Please enter the date (yyyy/mm/dd): ";
    cin >> findDay;
    return findDay;
}

// Deal with input: Time
Time AirQualityAnalyzer::processInputTime() const {
    Time findTime;
    cout << "Please enter the time (hh:mm:ss): ";
    cin >> findTime;
    return findTime;
}

// Get and print all the average value for each month
void AirQualityAnalyzer::printAllAvg() const {
    cout << "------------Average Temperature------------" << endl;
    for (auto &m : monthDataCollection)
        cout << m.getMonthString() << " " << fixed << setprecision(2) << m.getAvgTemp() << endl;

    cout << "------------Average RH------------" << endl;
    for (auto &m : monthDataCollection)
        cout << m.getMonthString() << " " << fixed << setprecision(2) << m.getAvgRH() << endl;

    cout << "------------Average AH------------" << endl;
    for (auto &m : monthDataCollection)
        cout << m.getMonthString() << " " << fixed << setprecision(2) << m.getAvgAH() << endl;
}

// Get and print all the highest value for each month
void AirQualityAnalyzer::printAllMax() const {
    cout << "------------Max Temperature------------" << endl;
    for (auto &m : monthDataCollection)
        cout << m.getMonthString() << " " << fixed << setprecision(2) << m.getMaxTemp() << endl;

    cout << "------------Max RH------------" << endl;
    for (auto &m : monthDataCollection)
        cout << m.getMonthString() << " " << fixed << setprecision(2) << m.getMaxRH() << endl;

    cout << "------------Max AH------------" << endl;
    for (auto &m : monthDataCollection)
        cout << m.getMonthString() << " " << fixed << setprecision(2) << m.getMaxAH() << endl;
}

// Get and print data of a given month
void AirQualityAnalyzer::printMonth() const {
    MonthlyData* targetMonth = processInputMonth();
    if (targetMonth != nullptr) {
        cout << "------------monthly data ------------" << endl;
        targetMonth->print();
    } else {
        cout << "Input month is out of range." << endl;
    }
}

// Validate double value in input
bool AirQualityAnalyzer::doubleValidator(const string &doubleString) {
    stringstream ss(doubleString);
    double value;
    ss >> value;
    if (ss.fail() || ss.peek() != EOF)
        return false;
    return true;
}

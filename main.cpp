#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <typeinfo>
#include <type_traits>
#include "AirQuality.h"
#include "Date.h"
#include "MonthlyData.h"
#include "Time.h"
#include "Vector.h"
using namespace std;

void readCSV(const string& fileName, MonthlyData months[], int& monthsIndex);
void displayMenu();
void processInput(const MonthlyData& month);

int main() {

    string fileName;
    fileName = "../AirQualityUCI_sample.csv"; //sample data 2 months
    //    fileName = "../AirQualityUCI_6months.csv"; //sample data 6 months
    //    fileName = "../AirQualityUCI.csv";//data all

    int TOTAL_MONTH = 15;
    MonthlyData months[TOTAL_MONTH];
    int monthsIndex = 0;
    MonthlyData monthsample;

    readCSV(fileName,months, monthsIndex);

    Date findDay;
    Time findTime;
    cout << "Please enter the date (yyyy/mm/dd):";
    cin >> findDay;
    cout << "Please enter the time (hh:mm:ss):";
    cin >> findTime;

    cout << findDay << endl;
    cout << findTime << endl;

    for (MonthlyData everyMonth : months){
        if(everyMonth.getMonth().sameMonth(findDay)){
            everyMonth.displayDataAt(findDay, findTime);
        }
    }

//    displayMenu();
//    processInput(month);

    return 0;
}

void readCSV(const string& fileName, MonthlyData months[], int& monthsIndex){
    ifstream inFile;
    string line;
    inFile.open(fileName);

    if (!inFile) {
        cout << "fail to open the file" << endl;
    }
    getline(inFile, line);

    while (getline(inFile, line)) {
        if (line.find_first_not_of(',') == string::npos) {
            break;
        }

        stringstream ss(line);
        string dateString, timeString, temperatureString, rhString, ahString;
        double temperature, rh, ah;

        getline(ss, dateString, ',');
        Date date(dateString);

        getline(ss, timeString, ',');
        Time time(timeString);

        for (int i = 0; i < 10; ++i) {
            ss.ignore(numeric_limits<streamsize>::max(), ',');
        }

        getline(ss, temperatureString, ',');
        try{
            temperature = stod(temperatureString);
        }catch (const invalid_argument& e) {
            cerr << "Invalid temperature value: " << temperatureString << endl;
        }

        getline(ss, rhString, ',');
        try{
            rh = stod(rhString);
        }catch (const invalid_argument& e) {
            cerr << "Invalid relative humidity value: " << rhString << endl;
        }

        getline(ss, ahString, ',');
        try{
            ah = stod(ahString);
        }catch (const invalid_argument& e) {
            cerr << "Invalid absolute humidity value: " << ahString << endl;
        }

        AirQuality air(date, time,temperature,rh,ah);

        //store the data into MonthlyData instance
        if (months[monthsIndex].isEmpty()){ //if the month is empty, set the date as comparator
            months[monthsIndex].setMonth(date);
            months[monthsIndex].push(air);
        }else if (months[monthsIndex].getMonth().sameMonth(date)){ // if the date belongs to this month, store it to the month
            months[monthsIndex].push(air);
        }else{ //if the date does not belong to current month
            monthsIndex++;
            cout << monthsIndex << endl;
            months[monthsIndex].setMonth(date);
        }
//        cout << date << time<< temperatureString<< rhString<< ahString<< endl; //for test purpose
    }
    inFile.close();
}

void displayMenu(){
    cout << "Please enter the corresponding number in the menu below: \n"
            "1) Prompt the user to enter month and the program should display the average temperature for that month.\n"
            "2) Prompt the user to enter month and the program should display the average relative humidity for that month.\n"
            "3) Prompt the user to enter month and the program should display the average absolute humidity for that month.\n"
            "4) Prompt the user to enter a valid date and time. The program should then display the temperature, and relative humidity at that date and time.\n"
            "5) Prompt the user to enter the month and the program should display the highest temperature for that month.\n"
            "6) Prompt the user to enter the month and the program should display the highest relative humidity value for that month.\n"
            "7) Prompt the user to enter the month and the program should display the highest absolute humidity for that month.\n"
            "8) Display the dates and times for a month when the temperature is higher than the average temperature for that month along with values of the temperature.\n"
            "9) Display the dates and times for a month when the relative humidity is higher than the average relative humidity for that month along with values of the relative humidity.\n"
            "10) Display the dates and times for a month when the absolute humidity is higher than the average absolute humidity for that month along with values of the absolute humidity." <<endl;
}

void processInput(const MonthlyData& month) {
    int menuItem;
    cout << "Enter your choice: ";
    cin >> menuItem;

    cout << menuItem;

    switch(menuItem){
        case 1:
            cout << "You are trying to know the average temperature for a month. \n"
                    "Please enter the month in the format of '08/2004': ";
        case 2:
            cout << "You are trying to know the average relative humidity for a month. \n"
                    "Please enter the month in the format of '08/2004': ";
        case 3:
            cout << "You are trying to know the average absolute humidity for a month. \n"
                    "Please enter the month in the format of '08/2004': ";
        case 4:
            cout << "You are trying to know the air quality data at the specific time of a day. \n"
                    "Please enter the month in the format of '08/2004': ";
        case 5:
            cout << "You are trying to know the average temperature for a month. \n"
                    "Please enter the month in the format of '08/2004': ";
        case 6:
            cout << "You are trying to know the average temperature for a month. \n"
                    "Please enter the month in the format of '08/2004': ";
        case 7:
            cout << "You are trying to know the average temperature for a month. \n"
                    "Please enter the month in the format of '08/2004': ";
        case 8:
            cout << "You are trying to know the average temperature for a month. \n"
                    "Please enter the month in the format of '08/2004': ";
        case 9:
            cout << "You are trying to know the average temperature for a month. \n"
                    "Please enter the month in the format of '08/2004': ";
        case 10:
            cout << "You are trying to know the average temperature for a month. \n"
                    "Please enter the month in the format of '08/2004': ";
    }
}
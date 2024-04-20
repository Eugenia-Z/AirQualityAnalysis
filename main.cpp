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
#include <limits>
#include <stdexcept>
#include "AirQuality.h"
#include "Date.h"
#include "MonthlyData.h"
#include "Time.h"
#include "AirQualityAnalyzer.h"
using namespace std;

void displayMenu();
int processInputMonth(const MonthlyData* months, int numMonths);
Date processInputDate();
Time processInputTime();

int main(){
    // load data from CSV file
    string fileName;
    fileName = "../AirQualityUCI.csv";
    AirQualityAnalyzer analyzer;
    analyzer.runAnalysis(fileName);

    // get monthly data, and number of months
    MonthlyData* months = analyzer.getMonths();
    int numMonths = analyzer.getNumMonths();

    while(true) {
        displayMenu();
        int menuItem;
        cout << "Enter your choice: ";
        cin >> menuItem;
        cin.ignore();

        switch (menuItem) {
            case 1: {
                cout << "You are trying to know the average temperature for a month. \n";
                int index;
                index = processInputMonth(months, numMonths);
                if(index==-1){
                    cout <<"Input month is out of range, please try again."<< endl;
                }else{
                    cout << "The average temperature for this month: " << fixed << setprecision(2)<< months[index].getAvgTemp() << endl;
                }
                break;
            }
            case 2: {
                cout << "You are trying to know the average relative humidity for a month. \n";
                int index;
                index = processInputMonth(months, numMonths);
                if(index==-1){
                    cout <<"Input month is out of range, please try again."<< endl;
                }else {
                    cout << "The average relative humidity for this month: " << fixed << setprecision(2)
                         << months[index].getAvgRH() << endl;
                }
                break;
            }
            case 3: {
                cout << "You are trying to know the average absolute humidity for a month. \n";
                int index;
                index = processInputMonth(months, numMonths);
                if(index==-1){
                    cout <<"Input month is out of range, please try again."<< endl;
                }else {
                    cout << "The average absolute humidity for this month: " << fixed << setprecision(2)
                         << months[index].getAvgAH() << endl;
                }
                break;
            }
            case 4: {
                cout << "You are trying to know the air quality data at the specific time of a day. \n";
                Date date = processInputDate();
                Time time = processInputTime();
                Date firstDay = Date(2004,3,10);
                if(date < Date(2004,3,10) || (date==Date(2004,3,10) && time <Time(18,0,0))||
                date > Date(2005,4,4) || (date==Date(2005,4,4) && time>Time(14,0,0))||
                time >Time(24,0,0) || time < Time(0,0,0)
                ){
                    cout << "Input date and time is out of range, please try again" << endl;
                }else {
                    time.setMinute(0);
                    time.setSecond(0);
                    cout << "Loading data for " << date.getYear() << "/" << date.getMonth() << "/" << date.getDay() <<
                         " " << time.getHour() << ":" << time.getMinute() << ":" << time.getSecond() << endl;
                    int i;
                    for (i = 0; i < numMonths; i++) {
                        if (months[i].getMonth().sameMonth(date)) {
                            break;
                        }
                    }
                    months[i].displayDataAt(date, time);
                }
                break;
            }
            case 5: {
                cout << "You are trying to know the highest temperature for a month. \n";
                int index;
                index = processInputMonth(months, numMonths);
                if(index==-1){
                    cout <<"Input month is out of range, please try again."<< endl;
                }else{
                    cout << "The highest temperature for this month: " << fixed << setprecision(2)<<months[index].getMaxTemp() << endl;
                }
                break;
            }
            case 6: {
                cout << "You are trying to know the highest relative humidity for a month. \n";
                int index;
                index = processInputMonth(months, numMonths);
                if(index==-1){
                    cout <<"Input month is out of range, please try again."<< endl;
                }else{
                    cout << "The highest relative humidity for this month: " << fixed << setprecision(2)<<months[index].getMaxRH() << endl;
                }
                break;
            }
            case 7: {
                cout << "You are trying to know the highest absolute humidity for a month. \n";
                int index;
                index = processInputMonth(months, numMonths);
                if(index==-1){
                    cout <<"Input month is out of range, please try again."<< endl;
                }else{
                    cout << "The highest absolute humidity for this month: " << fixed << setprecision(2)<<months[index].getMaxAH() << endl;
                }
                break;
            }
            case 8: {
                cout<< "You are trying to know the dates and times for a month when the temperature is higher than the average. \n";
                int index;
                index = processInputMonth(months, numMonths);
                if(index==-1){
                    cout <<"Input month is out of range, please try again."<< endl;
                }else {
                    months[index].displayHigherThanAvgTemp();
                }
                break;
            }
            case 9: {
                cout << "You are trying to know the dates and times for a month when the relative humidity is higher than the average.\n";
                int index;
                index = processInputMonth(months, numMonths);
                if(index==-1){
                    cout <<"Input month is out of range, please try again."<< endl;
                }else {
                    months[index].displayHigherThanAvgRH();
                }
                break;
            }
            case 10: {
                cout << "You are trying to know the dates and times for a month when the absolute humidity is higher than the average.\n";
                int index;
                index = processInputMonth(months, numMonths);
                if(index==-1){
                    cout <<"Input month is out of range, please try again."<< endl;
                }else {
                    months[index].displayHigherThanAvgAH();
                }
                break;
            }
            case 11: {
                cout << "Good bye.\n";
                return 1;
            }
            default: {
                cout << "Your input is not valid. Please try again.\n";
                cin.ignore();
                break;
            }
        }
    }
    return 0;
}

void displayMenu()
{
    cout << "-------------------Please enter the corresponding number in the menu below------------------\n"
            "1) Prompt the user to enter month and the program should display the average temperature for that month.\n"
            "2) Prompt the user to enter month and the program should display the average relative humidity for that month.\n"
            "3) Prompt the user to enter month and the program should display the average absolute humidity for that month.\n"
            "4) Prompt the user to enter a valid date and time. The program should then display the temperature, and relative humidity at that date and time.\n"
            "5) Prompt the user to enter the month and the program should display the highest temperature for that month.\n"
            "6) Prompt the user to enter the month and the program should display the highest relative humidity value for that month.\n"
            "7) Prompt the user to enter the month and the program should display the highest absolute humidity for that month.\n"
            "8) Display the dates and times for a month when the temperature is higher than the average temperature for that month along with values of the temperature.\n"
            "9) Display the dates and times for a month when the relative humidity is higher than the average relative humidity for that month along with values of the relative humidity.\n"
            "10) Display the dates and times for a month when the absolute humidity is higher than the average absolute humidity for that month along with values of the absolute humidity.\n"
            "11) Exit.\n"
            << endl;
}
// deal with input a date
Date processInputDate(){
    Date findDay;
    cout << "Please enter the date (yyyy/mm/dd):";
    cin >> findDay;
    return findDay;
}
// deal with input a time
Time processInputTime(){
    Time findTime;
    cout << "Please enter the time (hh:mm:ss):";
    cin >> findTime;
    return findTime;
}

// deal with input a month. return -1 when the month data is out of range.
int processInputMonth(const MonthlyData* months, int numMonths){
    string input;
    cout << "Please enter the month (yyyy/mm): ";
    cin >> input;
    string month_input = input + "/1";

    istringstream iss(month_input);
    int year, month, day;
    char delimiter;
    iss >> year >> delimiter >> month >> delimiter >> day;
    Date findDay(year,month,day);

    cout << "Loading data for "<< findDay.getYear() << "/" << findDay.getMonth() << endl;

    int i;
    for (i = 0; i < numMonths; i++){
        if (months[i].getMonth().sameMonth(findDay)){
            return i;
        }
    }
    cin.ignore();
    return -1;
}
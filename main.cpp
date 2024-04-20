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

int main()
{
    // load data from CSV file
    string fileName;
    fileName = "../AirQualityUCI.csv";
    AirQualityAnalyzer analyzer;
    analyzer.readCSV(fileName);

    // ask user input
    while (true)
    {
        displayMenu();
        int menuItem;
        cout << "Enter your choice: ";
        cin >> menuItem;
        cin.ignore();
        // call functions accroding to the user input
        switch (menuItem)
        {
        case 1:
        {
            cout << "You are trying to know the average temperature for a month. \n";
            int index;
            index = analyzer.processInputMonth();
            if (index == -1)
            {
                cout << "Input month is out of range, please try again." << endl;
            }
            else
            {
                cout << "The average temperature for this month: " << fixed << setprecision(2) << analyzer.getMonthAvgTemp(index) << endl;
            }
            break;
        }
        case 2:
        {
            cout << "You are trying to know the average relative humidity for a month. \n";
            int index;
            index = analyzer.processInputMonth();
            if (index == -1)
            {
                cout << "Input month is out of range, please try again." << endl;
            }
            else
            {
                cout << "The average relative humidity for this month: " << fixed << setprecision(2)
                     << analyzer.getMonthAvgRH(index) << endl;
            }
            break;
        }
        case 3:
        {
            cout << "You are trying to know the average absolute humidity for a month. \n";
            int index;
            index = analyzer.processInputMonth();
            if (index == -1)
            {
                cout << "Input month is out of range, please try again." << endl;
            }
            else
            {
                cout << "The average absolute humidity for this month: " << fixed << setprecision(2)
                     << analyzer.getMonthAvgAH(index) << endl;
            }
            break;
        }
        case 4:
        {
            cout << "You are trying to know the air quality data at the specific time of a day. \n";
            analyzer.displayDataAtDate();
            break;
        }
        case 5:
        {
            cout << "You are trying to know the highest temperature for a month. \n";
            int index;
            index = analyzer.processInputMonth();
            if (index == -1)
            {
                cout << "Input month is out of range, please try again." << endl;
            }
            else
            {
                cout << "The highest temperature for this month: " << fixed << setprecision(2) << analyzer.getMonthMaxTemp(index) << endl;
            }
            break;
        }
        case 6:
        {
            cout << "You are trying to know the highest relative humidity for a month. \n";
            int index;
            index = analyzer.processInputMonth();
            if (index == -1)
            {
                cout << "Input month is out of range, please try again." << endl;
            }
            else
            {
                cout << "The highest relative humidity for this month: " << fixed << setprecision(2) << analyzer.getMonthMaxRH(index) << endl;
            }
            break;
        }
        case 7:
        {
            cout << "You are trying to know the highest absolute humidity for a month. \n";
            int index;
            index = analyzer.processInputMonth();
            if (index == -1)
            {
                cout << "Input month is out of range, please try again." << endl;
            }
            else
            {
                cout << "The highest absolute humidity for this month: " << fixed << setprecision(2) << analyzer.getMonthMaxAH(index) << endl;
            }
            break;
        }
        case 8:
        {
            cout << "You are trying to know the dates and times for a month when the temperature is higher than the average. \n";
            int index;
            index = analyzer.processInputMonth();
            if (index == -1)
            {
                cout << "Input month is out of range, please try again." << endl;
            }
            else
            {
                analyzer.displayMonthHigherThanAvgTemp(index);
            }
            break;
        }
        case 9:
        {
            cout << "You are trying to know the dates and times for a month when the relative humidity is higher than the average.\n";
            int index;
            index = analyzer.processInputMonth();
            if (index == -1)
            {
                cout << "Input month is out of range, please try again." << endl;
            }
            else
            {
                analyzer.displayMonthHigherThanAvgRH(index);
            }
            break;
        }
        case 10:
        {
            cout << "You are trying to know the dates and times for a month when the absolute humidity is higher than the average.\n";
            int index;
            index = analyzer.processInputMonth();
            if (index == -1)
            {
                cout << "Input month is out of range, please try again." << endl;
            }
            else
            {
                analyzer.displayMonthHigherThanAvgAH(index);
            }
            break;
        }
        case 11:
        {
            cout << "Good bye.\n";
            return 1;
        }
        default:
        {
            cout << "Your input is not valid. Please try again.\n";
            cin.ignore();
            break;
        }
        }
    }
    return 0;
}
// display the menu
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
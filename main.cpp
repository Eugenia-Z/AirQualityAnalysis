#include "AirQualityAnalyzer.h"

// Function prototype
void displayMenu();

// Main program
int main() {
    int menuItem;
    AirQualityAnalyzer analyzer;
    string fileName = "../AirQualityUCI.csv";

    // Read data from CSV file
    analyzer.readCSV(fileName);

    // Prompt the user to input
    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> menuItem;
        cin.clear();
        cin.ignore(100, '\n');

        if (menuItem == 11) {
            cout << "Good bye!" << endl;
            break;
        }

        // Call functions according to the user input
        switch (menuItem) {
            case 1:
                analyzer.printMonthAvgTemp();
                break;
            case 2:
                analyzer.printMonthAvgRH();
                break;
            case 3:
                analyzer.printMonthAvgAH();
                break;
            case 4:
                analyzer.displayDataAtDate();
                break;
            case 5:
                analyzer.printMonthMaxTemp();
                break;
            case 6:
                analyzer.printMonthMaxRH();
                break;
            case 7:
                analyzer.printMonthMaxAH();
                break;
            case 8:
                analyzer.displayMonthHigherThanAvgTemp();
                break;
            case 9:
                analyzer.displayMonthHigherThanAvgRH();
                break;
            case 10:
                analyzer.displayMonthHigherThanAvgAH();
                break;
            default:
                cout << "Invalid input. Please try again." << endl;
        }
    }

    return 0;
}

// Display the menu
void displayMenu() {
    cout << "-------------------Please enter the corresponding number in the menu below------------------\n"
            "1. Query the average temperature for a specific month.\n"
            "2. Query the average relative humidity for a specific month.\n"
            "3. Query the average absolute humidity for a specific month.\n"
            "4. Query the temperature, and relative humidity at a specific date and time.\n"
            "5. Query the highest temperature for a month.\n"
            "6. Query the highest relative humidity for a month.\n"
            "7. Query the highest absolute humidity for a month.\n"
            "8. Query the dates and times along with values for a month when the temperature is higher than the average.\n"
            "9. Query the dates and times along with values for a month when the relative humidity is higher than the average.\n"
            "10. Query the dates and times along with values for a month when the absolute humidity is higher than the average.\n"
            "11. Exit.\n"
         << endl;
}
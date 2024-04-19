#include "AirQualityAnalyzer.h"
#include "AirQualityAnalyzer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

MonthlyData* AirQualityAnalyzer::getMonths() {
    return months;
}
int AirQualityAnalyzer::getNumMonths(){
    return NUM_MONTHS;
}

void AirQualityAnalyzer::runAnalysis(const std::string& fileName) {
    readCSV(fileName);
}

void AirQualityAnalyzer::readCSV(const std::string& fileName) {
    ifstream inFile;
    string line;
    inFile.open(fileName);

    if (!inFile){
        cout << "fail to open the file" << endl;
    }
    getline(inFile, line);

    while (getline(inFile, line))
    {
        // stop read CSV when get a line start with ","
        if (line[0] == ',') {
            break;
        }
        stringstream ss(line);
        string dateString, timeString, temperatureString, rhString, ahString;
        double temperature, rh, ah;

        getline(ss, dateString, ',');
        Date date(dateString);

        getline(ss, timeString, ',');
        Time time(timeString);

        for (int i = 0; i < 10; ++i){
            ss.ignore(numeric_limits<streamsize>::max(), ',');
        }

        getline(ss, temperatureString, ',');
        if(doubleValidator(temperatureString) && stod(temperatureString)>-199){
            temperature = stod(temperatureString);
        }else{
            temperature =NULL;
//            cout << "invalid temperature:" << temperatureString<< " modified to:"<<temperature<< endl;
//            continue;
        }

        getline(ss, rhString, ',');
        if(doubleValidator(rhString) && stod(rhString)>-199){
            rh = stod(rhString);
        }else{
            rh =NULL;
//            cout << "invalid rh:" << rhString<< " modified to:"<<rh<< endl;
//            continue;
        }

        getline(ss, ahString, ',');
        if(doubleValidator(ahString) && stod(ahString)>-199){
            ah = stod(ahString);
        }else{
            ah =NULL;
//            cout << "invalid ah:" << ahString<< " modified to:"<<ah<< endl;
//            continue;
        }
        AirQuality air(date, time, temperature, rh, ah);

        // store the data into MonthlyData instance
       if (monthsIndex >= 0 && months[monthsIndex].getMonth().sameMonth(date)) {// if the date belongs to this month, store it to the month
            months[monthsIndex].push(air);
        } else { // if the date does not belong to current month
//            cout << monthsIndex << " month data has been loaded."<< endl;
            months[++monthsIndex].setMonth(date);
            months[monthsIndex].push(air);
        }
    }
    inFile.close();
}

bool AirQualityAnalyzer::doubleValidator(const string& doubleString){
    stringstream ss(doubleString);
    double value;
    ss >> value;
    if (ss.fail() || ss.peek() != EOF) {
        return false;
    }
    return true;
}
void AirQualityAnalyzer::printAllAvg()const{
    cout << "------------avg temperature------------" << endl;
    for(int i=0; i<NUM_MONTHS;i++){
        cout << i << " month: "<< fixed <<setprecision(2)<< months[i].getAvgTemp() << endl;
    }
    cout << "------------avg rh------------" << endl;
    for(int i=0; i<NUM_MONTHS;i++){
        cout << i << " month: "<< fixed <<setprecision(2)<< months[i].getAvgRH() << endl;
    }
    cout << "------------avg ah------------" << endl;
    for(int i=0; i<NUM_MONTHS;i++){
        cout << i << " month: "<< fixed <<setprecision(2)<< months[i].getAvgAH() << endl;
    }
}
void AirQualityAnalyzer::printAllMax()const{
    cout << "------------max temperature------------" << endl;
    for(int i=0; i<NUM_MONTHS;i++){
        cout << i << " month: "<< fixed <<setprecision(2)<< months[i].getMaxTemp() << endl;
    }
    cout << "------------max rh------------" << endl;
    for(int i=0; i<NUM_MONTHS;i++){
        cout << i << " month: "<< fixed <<setprecision(2)<< months[i].getMaxRH() << endl;
    }
    cout << "------------max ah------------" << endl;
    for(int i=0; i<NUM_MONTHS;i++){
        cout << i << " month: "<< fixed <<setprecision(2)<< months[i].getMaxAH() << endl;
    }
}
void AirQualityAnalyzer::printMonth(int i){
    if(i>=NUM_MONTHS){
        throw "month index out of range";
    }
    cout << "------------monthly data ------------" << endl;
    months[i].print();
}
int AirQualityAnalyzer::processInputMonth(){
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
    for (i = 0; i < NUM_MONTHS; i++){
        if (months[i].getMonth().sameMonth(findDay)){
            return i;
        }
    }
    cin.ignore();
    return -1;
}
double AirQualityAnalyzer::getMonthAvgTemp(int index){
    return months[index].getAvgTemp();
}
double AirQualityAnalyzer::getMonthAvgRH(int index){
    return months[index].getAvgRH();
}
double AirQualityAnalyzer::getMonthAvgAH(int index){
    return months[index].getAvgAH();
}
double AirQualityAnalyzer::getMonthMaxTemp(int index){
    return months[index].getMaxTemp();
}
double AirQualityAnalyzer::getMonthMaxRH(int index){
    return months[index].getMaxRH();
}
double AirQualityAnalyzer::getMonthMaxAH(int index){
    return months[index].getMaxAH();
}
void AirQualityAnalyzer::displayMonthHigherThanAvgTemp(int index){
    months[index].displayHigherThanAvgTemp();
}
void AirQualityAnalyzer::displayMonthHigherThanAvgRH(int index){
    months[index].displayHigherThanAvgRH();
}
void AirQualityAnalyzer::displayMonthHigherThanAvgAH(int index){
    months[index].displayHigherThanAvgAH();
}
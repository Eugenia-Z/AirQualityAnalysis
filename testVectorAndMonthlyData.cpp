#include "VectorLinkedList.h"
#include "Time.h"
#include "Date.h"
#include "AirQuality.h"
#include "MonthlyData.h"
#include <stdexcept>
#include <iostream>
using namespace std;

int main(){
    // Create an empty VectorLinkedList
    VectorLinkedList<AirQuality> vec;
    MonthlyData m;
    // Test isEmpty() on an empty VectorLinkedList AND MonthlyData
    cout << "Is vectorLinkedList empty? " << (vec.empty()? "Yes": "No") << endl;
    cout << "Is VectorLinkedList empty? " << (m.isEmpty()? "Yes": "No") << endl;

    // Create some AirQuality instances
    AirQuality aq0(Date(12,12,2004), Time (12,0,0), 25.5, 60.0, 0.044);
    AirQuality aq1(Date(13,11,2004), Time (11,0,0), 25.4, 60.1, 0.045);
    AirQuality aq2(Date(14,12,2004), Time (14,0,0), 26.2, 58.5, 0.042);
//    AirQuality aq3(Date(12, 4, 2024), Time(14), 27.8, 55.5, 0.039);

    // Push AirQuality instances into the VectorLinkedList
    vec.push_back(aq0);
    vec.push_back(aq1);
    vec.push_back(aq2);
//    vec.push(aq3);

    // Test push(), getMax(), getAvg()
    m.push(aq0);
    m.push(aq1);
    m.push(aq2);
    cout << m.isEmpty() << endl;
    cout << m.getSize() << endl;
    cout << "Max T: " << m.getMaxTemp() << endl;
    cout << "Max RH: " << m.getMaxRH() << endl;
    cout << "Max AH: " << m.getMaxAH() << endl;
    cout << "Avg T: " << m.getAvgTemp() << endl;
    cout << "Avg RH: " << m.getAvgRH() << endl;
    cout << "Avg AH: " << m.getAvgAH() << endl;
    // Test search()
    m.displayDataAt(Date(12,12,2004), Time (12,0,0));
    m.displayDataAt(Date(12,13,2004), Time (12,0,0));
    // test higher()
    m.displayHigherThanAvgTemp();
    m.displayHigherThanAvgRH();
    m.displayHigherThanAvgAH();


    // Test empty() on a non-empty VectorLinkedList
    cout << "Is VectorLinkedList empty? " << (vec.empty()? "Yes": "No") << endl;


    //Test pop() to remove elements from the VectorLinkedList
    vec.pop_back();
    vec.pop_back();
    cout << "Size after pop: " << vec.getSize() << endl;

    // Push more AirQuality instances
    AirQuality aq3(Date(1,4,2024), Time(15,0,0), 25.5, 60.0, 0.045);
    AirQuality aq4(Date(1,2,2024), Time(15,0,0), 25.5, 60.0, 0.045);
    AirQuality aq5(Date(17,1,2024), Time(16,0,0), 29.1, 52.5, 0.035);

    // Test getSize()
    cout << "Size of VectorLinkedList after resizing: " << vec.getSize() << endl;

    // Test Iterator
    cout << "Elements in the vec: ";
    for (VectorLinkedList<AirQuality>::Iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }

    return 0;

}
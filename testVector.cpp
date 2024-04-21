#include "VectorLinkedList.h"
#include "Time.h"
#include "Date.h"
#include "AirQuality.h"
#include <stdexcept>
#include <iostream>
using namespace std;

int main()
{
    // Create an empty VectorLinkedList
    VectorLinkedList<AirQuality> vec;
    // Test isEmpty() on an empty VectorLinkedList AND MonthlyData
    cout << "Is vectorLinkedList empty? " << (vec.empty() ? "Yes" : "No") << endl;

    // Create some AirQuality instances
    AirQuality aq0(Date(2004, 12, 31), Time(12, 0, 0),
                   25.5, 60.0, 0.044);
    AirQuality aq1(Date(2004, 12, 18), Time(11, 0, 0),
                   25.4, 60.1, 0.045);
    AirQuality aq2(Date(2004, 12, 2), Time(14, 0, 0),
                   26.2, 58.5, 0.042);

    // Push AirQuality instances into the VectorLinkedList
    vec.push_back(aq0);
    vec.push_back(aq1);
    vec.push_back(aq2);


    // Test empty() on a non-empty VectorLinkedList
    cout << "Is VectorLinkedList empty? " << (vec.empty() ? "Yes" : "No") << endl;

    // Test pop() to remove elements from the VectorLinkedList
    vec.pop_back();
    vec.pop_back();
    cout << "Size after pop: " << vec.getSize() << endl;

    // Test [] operator
    cout << "Element at index 0: " << vec[0] << endl;
    vec[0] = AirQuality(Date(2004, 12, 29), Time(10, 0, 0),
                        20.0, 70.0, 0.03);
    cout << "Element at index 0 after modification: " << vec[0] << endl;
    cout << vec[vec.getSize() - 1] << endl;

    // Test out-of-bounds access
    try
    {
        cout << "Attempting to access out-of-bounds element: " << vec[1] << endl;
    }
    catch (const out_of_range &e)
    {
        cout << "Caught out-of-range exception: " << e.what() << endl;
    }

    // Push more AirQuality instances
    AirQuality aq3(Date(2004, 12, 20), Time(15, 0, 0),
                   25.5, 60.0, 0.045);
    AirQuality aq4(Date(2004, 12, 21), Time(15, 0, 0),
                   25.5, 60.0, 0.045);
    AirQuality aq5(Date(2004, 12, 25), Time(16, 0, 0),
                   29.1, 52.5, 0.035);

    vec.push_back(aq3);
    vec.push_back(aq4);
    vec.push_back(aq5);
    // Test getSize()
    cout << "Size of VectorLinkedList after resizing: " << vec.getSize() << endl;

    // Test Iterator
    cout << "Elements in the vec: " << endl;
    for (VectorLinkedList<AirQuality>::Iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << " ";
    }

    return 0;
}
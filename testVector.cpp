//
// Created by Eugenia Zhang on 4/8/24.
//

#include "Vector.h"
#include "Time.h"
#include "Date.h"
#include "AirQuality.h"
#include <stdexcept>
#include <iostream>
using namespace std;

int main(){
    // Create an empty vector
    Vector<AirQuality> vec;

    // Test isEmpty() on an empty vector
    cout << "Is vector empty? " << (vec.isEmpty()? "Yes": "No") << endl;

    // Create some AirQuality instances
    AirQuality aq0(Date(12,12,2004), Time (12), 25.5, 60.0, 0.045);
    AirQuality aq1(Date(13,11,2004), Time (11), 25.5, 60.0, 0.045);
    AirQuality aq2(Date(14,12,2004), Time (14), 26.2, 58.5, 0.042);
   // AirQuality aq3(Date(12, 4, 2024), Time(14), 27.8, 55.5, 0.039);

    // Push AirQuality instances into the vector
    vec.push(aq0);
    vec.push(aq1);
    vec.push(aq2);
    //vec.push(aq3);

    // Test print the vector contents
    vec.print();

    // Test isEmpty() on a non-empty vector
    cout << "Is vector empty? " << (vec.isEmpty()? "Yes": "No") << endl;


     //Test pop() to remove elements from the vector
    vec.pop();
    vec.pop();
    cout << "Size after pop: " << vec.getSize() << endl;

    // Test exception handling when popping from an empty vector
    try{
        vec.pop();
        vec.pop(); // this will throw an exception
    } catch (const out_of_range& e){
        cout <<"Exception caught: " << e.what() << endl;
    }

    // Push more AirQuality instances to trigger resize()
    AirQuality aq3(Date(1,4,2024), Time(15), 25.5, 60.0, 0.045);
    AirQuality aq4(Date(1,2,2024), Time(15), 25.5, 60.0, 0.045);
    AirQuality aq5(Date(17,1,2024), Time(16), 29.1, 52.5, 0.035);
    AirQuality aq6(Date(10,2,2024), Time(17), 23.5, 61.0, 0.035);
    AirQuality aq7(Date(19,5,2024), Time(18), 24.5, 62.0, 0.025);
    AirQuality aq8(Date(1,6,2024), Time(19), 27.5, 63.0, 0.044);
    AirQuality aq9(Date(1,7,2024), Time(20), 45.5, 64.0, 0.046);
    AirQuality aq10(Date(23,8,2024), Time(21), 15.5, 65.0, 0.037);
    AirQuality aq11(Date(5,9,20219), Time(22), 22.5, 66.0, 0.048);
    AirQuality aq12(Date(18,10,2024), Time(23), 21.5, 67.0, 0.049);
    AirQuality aq13(Date(24,11,2024), Time(24), 19.5, 68.0, 0.035);

    vec.push(aq3);
    vec.push(aq4);
    vec.push(aq5);
    vec.push(aq6);
    vec.push(aq7);
    vec.push(aq8);
    vec.push(aq9);
    vec.push(aq10);
    vec.push(aq11);
    vec.push(aq12);
    vec.push(aq13);


    // Test getSize()
    cout << "Size of vector after resizing: " << vec.getSize() << endl;

    // Test Iterator
    AirQuality* ptr;
    Vector<AirQuality> ::Iterator it(ptr);
    cout << "Vector contents: " << endl;
    for (it = vec.begin(); it != vec.end(); ++it){
        cout << *it;
    }
    cout << endl;
    return 0;


}
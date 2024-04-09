//
// Created by Eugenia Zhang on 4/7/24.
//

#include "Vector.h"
#include "AirQuality.h"
#include <stdexcept>
#include <iostream>

using namespace std;

template<typename T>
Vector<T>::Vector() : size(0), capacity(11), arr(new T[capacity]) {}

template<typename T>
Vector<T>:: ~Vector(){
    delete[] arr;
};

template<typename T>
bool Vector<T>:: isEmpty() const{
    return size == 0;
}
template<typename T>
void Vector<T>::push(const T& value){
    if(size >= capacity){
        resize();
    }
    arr[size++] = value;
}
template<typename T>
void Vector<T>::pop(){
    if(isEmpty()){
        throw out_of_range("Vector is empty");
    }
    --size;
}

template<typename T>
void Vector<T>:: print() const{
    cout << "Vector contents:" << endl;
    for(int i = 0; i < size; ++i){
        cout << arr[i];
    }
    cout << endl;
}

template<typename T>
int Vector<T>::getSize() const {
    return size;
}

template<typename T>
typename Vector<T>:: Iterator Vector<T>:: begin(){
    return Iterator(arr);
}
template<typename T>
typename Vector<T>:: Iterator Vector<T>:: end(){
    return Iterator(arr + size);
}


template<typename T>
void Vector<T> :: resize(){
    capacity *= 2;
    T* newArr = new T[capacity];
    for (int i=0; i<size; ++i){
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
}

template class Vector<AirQuality>;

//
// Created by Eugenia Zhang on 4/14/24.
//

#include "VectorLinkedList.h"
#include "AirQuality.h"
#include "MonthlyData.h"

template<typename T>
VectorLinkedList<T>::VectorLinkedList(): head(nullptr), size(0) {}

template<typename T>
VectorLinkedList<T>::~VectorLinkedList() { clear(); }

template<typename T>
void VectorLinkedList<T>::push_back(const T& val) {
    Node *newNode = new Node(val);
    if (!head) {
        head = newNode;
    } else {
        Node *current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
    size++;
}

template<typename T>
void VectorLinkedList<T>::pop_back() {
    if (!head) {
        return;
    }
    if (!head->next) {
        delete head;
        head = nullptr;
    } else {
        Node *current = head;
        Node *prev = nullptr;
        while (current->next) {
            prev = current;
            current = current->next;
        }
        delete current;
        prev->next = nullptr;
    }
    size--;
}

template<typename T>
size_t VectorLinkedList<T>::getSize() const {
    return size;
}

template<typename T>
bool VectorLinkedList<T>::empty() const {
    return size == 0;
}

template<typename T>
void VectorLinkedList<T>::clear() {
    Node *current = head;
    while (current) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    size = 0;
}

template<typename T>
typename VectorLinkedList<T>::Iterator VectorLinkedList<T>::begin() const {
    return Iterator(head);
}

template<typename T>
typename VectorLinkedList<T>::Iterator VectorLinkedList<T>::end() const {
    return Iterator(nullptr);
}

template<typename T>
T &VectorLinkedList<T>::operator[](size_t index) {
    if (index >= size) {
        throw out_of_range("Index out of bounds");
    }
    Node *current = head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

template class VectorLinkedList<AirQuality>;

template class VectorLinkedList<MonthlyData>;
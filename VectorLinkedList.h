//
// Created by Eugenia Zhang on 4/14/24.
//

#ifndef FP_VECTORLINKEDLIST_H
#define FP_VECTORLINKEDLIST_H

#include <iostream>

template<typename T>
class VectorLinkedList {
private:
    struct Node{
        T data;
        Node* next;
        Node(const T& val):data(val), next(nullptr){}
    };

    Node* head;
    size_t size;

public:
    // Nested Iterator class
    class Iterator{
    private:
        Node* current;
    public:
        Iterator(Node* node): current(node){}

        T& operator*() const{
            return current->data;
        }

        Iterator& operator++(){
            current = current->next;
            return *this;
        }

        bool operator==(const Iterator& other)const{
            return current == other.current;
        }
        bool operator!=(const Iterator& other)const{
            return !(*this == other);
        }
    };

    VectorLinkedList();
    ~VectorLinkedList();

    void push_back(const T& val);
    void pop_back();
    size_t getSize() const;
    bool empty() const;
    void clear();
    Iterator begin() const;
    Iterator end() const;

    // [] operator overload
    T& operator[](size_t index);
};




#endif //FP_VECTORLINKEDLIST_H

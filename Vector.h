
#ifndef FINAL_PROJECT_VECTOR_H
#define FINAL_PROJECT_VECTOR_H

template <typename T>
class Vector {
public:
    // Iterator Implementation
    class Iterator{
    public:
        Iterator(){}
        Iterator(T* ptr): m_ptr(ptr){}

        T& operator*() const{
            return *m_ptr;
        }

        Iterator& operator++(){
            ++m_ptr;
            return *this;
        }

//        Iterator operator++(int){
//            Iterator temp = *this;
//            ++m_ptr;
//            return temp;
//        }

        bool operator==(const Iterator& other) const{
            return m_ptr == other.m_ptr;
        }
        bool operator!=(const Iterator& other) const{
            return m_ptr != other.m_ptr;
        }
    private:
        T* m_ptr;
    };

    Vector();
    ~Vector();

    bool isEmpty() const;
    void push(const T& value);
    void pop();
    void print() const;
    int getSize() const;
    Iterator begin() const;
    Iterator end() const;

private:
    T* arr;
    int size;
    int capacity;
    void resize();
};

#endif //FINAL_PROJECT_VECTOR_H

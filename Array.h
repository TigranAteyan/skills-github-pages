#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <typename T>
class Array {
private:
    T* arr;
    int n;
    int count;

    void resize(int new_n) {
        T* new_arr = new T[new_n];
        for (int i = 0; i < count; ++i) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        n = new_n;
    }

public:
    Array(int n2 = 2) : n(n2), count(0) {
        arr = new T[n];
    }

    ~Array() {
        delete[] arr;
    }

    int size() const {
        return count;
    }

    bool isEmpty() const {
        return count == 0;
    }

    void add(const T& item) {
        if (count == n) {
            resize(n * 2);
        }
        arr[count++] = item;
    }

    void removeAt(int index) {
        if (index < 0 || index >= count) {
            throw std::out_of_range("Index out of range");
        }
        for (int i = index; i < count - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --count;
        if (count <= n / 4) {
            resize(n / 2);
        }
    }

    T& at(int index) {
        if (index < 0 || index >= count) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    T& operator[](int index) {
        return at(index);
    }



};

#endif 

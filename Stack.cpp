//
// Created by one for all on 17/09/2020.
//

#include "Stack.h"

template<typename T>
Stack<T>::Stack() : capacity{2}, count{ 0 } {
    data = allocate_and_copy(2, 0);
}

template<typename T>
Stack<T>::Stack(std::size_t capacity) : capacity{ capacity }, count{ 0 } {
    data = allocate_and_copy(capacity, 0);
}

template<typename T>
void Stack<T>::push(T item) {
    if (count >= capacity) allocate_and_copy(count * 2, 1);
    data[count++] = item;
}

template<typename T>
void Stack<T>::print() {
    std::cout << "[ ";
    for (int i = 0; i < count; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << "]\n";
}

template<typename T>
T *Stack<T>::allocate_and_copy(std::size_t newCapacity, char _copy) {
    T *other = new T[capacity];
    if (_copy) {
        for (std::size_t i{}; i < count; ++i) other[i] = data[i];
        data = other;
        capacity = newCapacity;
        return data;
    }
    return other;
}

template<typename T>
void Stack<T>::pop(){
    data[count--] = 0;
}

template<typename T>
T& Stack<T>::top() {
    return data[count];
}

template <typename T>
bool Stack<T>::empty() {
    return count == 0;
}

template<typename T>
std::size_t Stack<T>::size() {
    return count;
}

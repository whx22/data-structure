//
// Created by whx on 22-11-30.
//

#ifndef CLION_MY_STACK_HPP
#define CLION_MY_STACK_HPP

#include <iostream>
#include <exception>
using namespace std;

#define MAXSIZE 100

template<class T>
class Stack {
public:
    Stack() : m_top(-1) {}
    void push(const T& element);
    T pop();
    void clear();
    T top() const;
    int size() const;
    bool is_empty() const;
private:
    T m_data[MAXSIZE];
    int m_top;
};

template<class T>
void Stack<T>::push(const T& element) {
    if (this->m_top == MAXSIZE) {
        throw out_of_range("error : the stack is full");
    }
    this->m_data[++(this->m_top)] = element;
}

template<class T>
T Stack<T>::pop() {
    if (this->m_top == -1) {
        throw out_of_range("error : the stack is empty");
    }
    return this->m_data[(this->m_top)--];
}

template<class T>
void Stack<T>::clear() {
    this->m_top = -1;
}

template<class T>
T Stack<T>::top() const {
    if (this->m_top == -1) {
        throw out_of_range("error : the stack is empty");
    }
    return this->m_data[this->m_top];
}

template<class T>
bool Stack<T>::is_empty() const {
    if (this->m_top == -1) {
        return true;
    }
    else {
        return false;
    }
}

template<class T>
int Stack<T>::size() const {
    return this->m_top + 1;
}

#endif //CLION_MY_STACK_HPP

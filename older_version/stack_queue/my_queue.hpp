#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

#include <iostream>
#include <exception>
using namespace std;

#define MAXSIZE 100

template<class T>
class Queue {
public:
    Queue() : m_front(0), m_rear(0) {}
    void enter(const T& element);
    T exit();
    void clear();
    int size() const;
    bool is_empty() const;
private:
    T m_data[MAXSIZE];
    int m_front;
    int m_rear;
};

template<class T>
void Queue<T>::enter(const T& element) {
    if (this->m_front == (this->m_rear + 1) % MAXSIZE) {
        throw out_of_range("error : the queue is full");
    }
    this->m_rear = (this->m_rear + 1) % MAXSIZE;
    this->m_data[this->m_rear] = element;
}

template<class T>
T Queue<T>::exit() {
    if (this->m_front == this->m_rear) {
        throw out_of_range("error : the queue is empty");
    }
    this->m_front = (this->m_front + 1) % MAXSIZE;
    return this->m_data[this->m_front];
}

template<class T>
void Queue<T>::clear() {
    this->m_front = 0;
    this->m_rear = 0;
}

template<class T>
int Queue<T>::size() const {
    return (this->m_rear + MAXSIZE - this->m_front) % MAXSIZE;
}

template<class T>
bool Queue<T>::is_empty() const {
    if (this->m_front == this->m_rear) {
        return true;
    }
    return false;
}

#endif
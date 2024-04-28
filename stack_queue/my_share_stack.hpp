#ifndef _SHARE_STACK_HPP_
#define _SHARE_STACK_HPP_

#include <iostream>
#include <exception>
using namespace std;

#define MAXSIZE 100

template<class T>
class ShareStack {
public:
    ShareStack() : top[0](-1), top[1](MAXSIZE) {}
    void init();
    bool is_empty();
    bool is_full();
private:
    T data[MAXSIZE];
    int top[2];
};

template<class T>
void ShareStack<T>::init() {
    this->top[0] = -1;
    this->top[1] = MAXSIZE;
}

template<class T>
bool ShareStack<T>::is_empty() {
    if (this->top[0] == -1 && this->top[1] == MAXSIZE) {
        return true;
    }
    else {
        return false;
    }
}

template<class T>
bool ShareStack<T>::is_full() {
    if (this->top[0] + 1 == this->top[1]) {
        return true;
    }
    else {
        return false;
    }
}

#endif  // _SHARE_STACK_HPP_
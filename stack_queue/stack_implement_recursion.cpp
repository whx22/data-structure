// stack implement recursion

#include <iostream>
using namespace std;
#include "my_stack.hpp"
#include "my_queue.hpp"

// solution by recursion
int calFByRecursion(const int& m) {
    if (m == 0) {
        return 1;
    }
    else {
        return m * calFByRecursion(m / 3);
    }
}

// solution by stack
int calFByStack(int m) {
    Stack<int> assist_stack;
    int cnm = 1;
    while (m != 0) {
        assist_stack.push(m);
        m /= 3;
    }
    while (!assist_stack.is_empty()) {
        cnm *= assist_stack.pop();
    }
    return cnm;
}
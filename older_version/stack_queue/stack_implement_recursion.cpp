// Stack Implement Recursion

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
    int cnm = 1;
    Stack<int> assist_S;
    while (m != 0) {
        assist_S.push(m);
        m /= 3;
    }
    while (!assist_S.is_empty()) {
        cnm *= assist_S.pop();
    }
    return cnm;
}
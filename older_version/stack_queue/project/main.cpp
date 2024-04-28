#include <iostream>
#include <cstring>
using namespace std;
#include "my_queue.hpp"
#include "my_stack.hpp"
#include "expression_function.h"

// expression_conversion.cpp test code
template<class T>
void printArray(T a_string[], const unsigned int& length) {
    cout << "the length of this string is : " << length << endl;
    for (int i = 0; i < length; ++i) {
        cout << a_string[i];
    }
    cout << endl;
}

template<class T>
void reverse(T array[], const unsigned int& length) {
    T temp;
    for (int i = 0, j = length - 1; i < j; ++i, --j) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void test_reverse() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(nums) / sizeof(nums[0]);
    reverse<int>(nums, length);
    printArray<int>(nums, length);
}

void assignString(const char* a_string, char* result, const unsigned int& length) {
    for (int i = 0; i < length; ++i) {
        result[i] = a_string[i];
    }
    result[length] = '\0';
}

void test_conversion() {
    char infix_1[] = "1+2-3*((4+5)/6-7)+8";
    unsigned int length_1 = strlen(infix_1);
    char infix_2[] = "1+2-3*((4+5)/6-7)+8";
    unsigned int length_2 = strlen(infix_2);
    printArray(infix_1, length_1);
    printArray(infix_2, length_2);

    // calculation the postfix expression of infix_1
    Stack<char> s1;
    infixToPostfix(infix_1, s1);

    // // solution 1 : print the postfix expression of infix_1
    // cout << "the postfix expression is : " << endl;
    // Stack<char> temp;
    // while (!s1.is_empty()) {
    //     temp.push(s1.top());
    //     s1.pop();
    // }
    // while (!temp.is_empty()) {
    //     cout << temp.top();
    //     temp.pop();
    // }
    // cout << endl;
    // temp.clear();

// solution 2 : print the postfix expression of infix_1
    {
        cout << "the postfix expression is : " << endl;
        Queue<char> q1;
        while (!s1.is_empty()) {
            q1.enter(s1.top());
            s1.pop();
        }

        string str1;
        while (!q1.is_empty()) {
            str1 += q1.exit();
        }
        const char* temp = str1.data();

        char result[strlen(temp) + 1];
        assignString(temp, result, strlen(temp));

        reverse(result, strlen(result));
        printArray(result, strlen(result));
    }

    // calculation the prefix expression of infix_2
    Stack<char> s2;
    infixToPrefix(infix_2, strlen(infix_2), s2);

    // print the prefix expression of infix_2
    cout << "the prefix expression is : " << endl;
    while (!s2.is_empty()) {
        cout << s2.top();
        s2.pop();
    }
    cout << endl;
}

// expression_calculate.cpp test code
void test_calculation() {
    char expression_1[] = "1+2-3*((4+5)/6-7)+8";
    char expression_2[] = "13+4*";
    char expression_3[] = "+12";
    unsigned int length = 3;
    cout << expression_1 << " = " << calInfix(expression_1) << endl;
    cout << expression_2 << " = " << calPostfix(expression_2) << endl;
    cout << expression_3 << " = " << calPrefix(expression_3, length) << endl;
}

int main() {
    test_calculation();
    return 0;
}

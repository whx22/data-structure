// this is test file

#include <iostream>
#include <exception>
#include <cstring>
using namespace std;
#include "my_stack.hpp"
#include "my_queue.hpp"
#include "expression_function.h"

// my_stack.hpp test code 
void test_1(void) {
    Stack<char> s;
    for (int i = 'a'; i <= 'z'; ++i) {
        s.push(i);
    }

    cout << "At the moment, the size of stack is : " << s.size() << endl;

    //s.clear();
    cout << "At the moment, the size of stack is : " << s.size() << endl;

    while (!s.is_empty()) {
        cout << "the top at the moment is : " << s.pop() << endl;
    }

    cout << "At the moment, the size of stack is : " << s.size() << endl;

    if (s.is_empty()) {
        cout << "the stack is empty" << endl;
    }
    else {
        cout << "the stack isn't empty" << endl;
    }
}

// my_queue.hpp test code
void test_2(void) {
    Queue<char> q;
    for (int i = 'a'; i <= 'z'; ++i) {
        q.enter(i);
    }

    cout << "At the moment, the size of queue is : " << q.size() << endl;

    while (!q.is_empty()) {
        cout << "the front at the moment is : " << q.exit() << endl;
    }

    cout << "At the moment, the size of queue is : " << q.size() << endl;

    if (q.is_empty()) {
        cout << "the queue is empty" << endl;
    }
    else {
        cout << "the queue isn't empty" << endl;
    }
}

// expression_conversion.hpp test code
template<class T>
void printArray(T a_string[], int length) {
    cout << "the length of this string is : " << length << endl;
    for (int i = 0; i < length; ++i) {
        cout << a_string[i];
    }
    cout << endl;
}

template<class T>
void reverse(T array[], int length) {
    T temp;
    for (int i = 0, j = length - 1; i < j; ++i, --j) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void test_reverse(void) {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(nums) / sizeof(nums[0]);
    reverse<int>(nums, length);
    printArray<int>(nums, length);
}

void assignString(const char* a_string, char* result, int length) {
    for (int i = 0; i < length; ++i) {
        result[i] = a_string[i];
    }
    result[length] = '\0';
}

void test_3(void) { 
    char infix_1[] = "1+2-3*((4+5)/6-7)+8";
    int length_1 = strlen(infix_1);
    char infix_2[] = "1+2-3*((4+5)/6-7)+8";
    int length_2 = strlen(infix_2);
    printArray(infix_1, length_1);
    printArray(infix_2, length_2);

    // calculation the postfix expresion of infix_1
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

    // calculation the prefix expresion of infix_2
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

// expression_calculation.hpp test code
void test_4(void) {
    char expression_1[] = "1+2-3*((4+5)/6-7)+8";
    char expression_2[] = "13+4*";
    char expression_3[] = "*7+12";
    cout << expression_1 << " = " << calInfix(expression_1) << endl;
    cout << expression_2 << " = " << calPostfix(expression_2) << endl;
    cout << expression_3 << " = " << calPrefix(expression_3, strlen(expression_3)) << endl;
}

int main(void) {
    test_4();

    return EXIT_SUCCESS;
}
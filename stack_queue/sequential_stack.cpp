/*
 * Stack : A pile of things.
 * Characteristics ：First In, Last Out(FILO)
 * Allow Insertion and Deletion : Top 
 * 
 * Sequential Stack
 */
#include <iostream>
#include <exception>
using namespace std;

#define MAXSIZE 100

typedef struct {
    int data[MAXSIZE];
    int top;    // 指向栈顶元素
} Stack;

// Initialize Stack
void initStack(Stack& stack) {
    stack.top = -1;
}

// Push Stack 
void push(Stack& stack,const int& element) {
    if (stack.top == MAXSIZE - 1) {
        throw out_of_range("error : the stack is full");
    }
    stack.data[++(stack.top)] = element;
}

// Pop Stack
void pop(Stack& stack, int& element) {
    if (stack.top == -1) {
        throw out_of_range("error : the stack is empty");
    }
    element = stack.data[(stack.top)--];
}

int main(void) {
    return EXIT_SUCCESS;
}
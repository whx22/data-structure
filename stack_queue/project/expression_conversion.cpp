//
// Created by whx on 23-3-1.
//
#ifndef EXPRESSION_CONVERSION_CPP
#define EXPRESSION_CONVERSION_CPP


#include "expression_function.h"

void infixToPostfix(char infix[], Queue<char>& result_queue) {
    Stack<char> assist_stack;
    int i = 0;
    while (infix[i] != '\0') {
        if (infix[i] >= '0' && infix[i] <= '9') {
            result_queue.enter(infix[i]);
            ++i;
        }
        else if (infix[i] == '(') {
            assist_stack.push(infix[i]);
            ++i;
        }
        else if (infix[i] == '+'
                || infix[i] == '-'
                || infix[i] == '*'
                || infix[i] == '/') {
            if (assist_stack.is_empty()
                || assist_stack.top() == '('
                || getPriority(infix[i]) > getPriority(assist_stack.top())) {
                assist_stack.push(infix[i]);
                ++i;
            }
            else {
                result_queue.enter(assist_stack.pop());
            }
        }
        else if (infix[i] == ')') {
            while (assist_stack.top() != '(') {
                result_queue.enter(assist_stack.pop());
            }
            assist_stack.pop();
            ++i;
        }
    }
    while (!assist_stack.is_empty()) {
        result_queue.enter(assist_stack.pop());
    }
}

void infixToPrefix(char infix[], const unsigned int& length, Stack<char>& result_stack) {
    Stack<char> assist_stack;
    int i = length - 1;
    while (i >= 0) {
        if (infix[i] >= '0' && infix[i] <= '9') {
            result_stack.push(infix[i]);
            --i;
        }
        else if (infix[i] == ')') {
            assist_stack.push(infix[i]);
            --i;
        }
        else if (infix[i] == '+'
                || infix[i] == '-'
                || infix[i] == '*'
                || infix[i] == '/') {
            if (assist_stack.is_empty()
                || assist_stack.top() == ')'
                || getPriority(infix[i]) >= getPriority(assist_stack.top())) {
                assist_stack.push(infix[i]);
                --i;
            }
            else {
                result_stack.push(assist_stack.pop());
            }
        }
        else if (infix[i] == '(') {
            while (assist_stack.top() != ')') {
                result_stack.push(assist_stack.pop());
            }
            assist_stack.pop();
            --i;
        }
    }
    while (!assist_stack.is_empty()) {
        result_stack.push(assist_stack.pop());
    }
}


#endif // EXPRESSION_CONVERSION_CPP
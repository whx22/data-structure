//
// Created by whx on 22-11-30.
//

#include "expression_function.h"

/*
 * FunctionName : priority()
 * Description : calculate the operator priority
 * Called By : infixToPostfix() && infixToPrefix() && calInfix()
 * Parameter 1 : a operator
 * Return : priority of operator
 */
int priority(const char& a_operator) {
    if (a_operator == '+' || a_operator == '-') {
        return 1;
    }
    else if (a_operator == '*' || a_operator == '/') {
        return 2;
    }
    else {
        return 0;
    }
}

/*
 * FunctionName : infixToPostfix()
 * Description : infix expression translate into post expression
 * Calls : priority()
 * Parameter 1 : infix expression
 * Parameter 2 : result stack
 */
void infixToPostfix(char infix[], Stack<char>& result_s) {
    Stack<char> assist_s;   // assist stack
    int i = 0;  // log infix[] index 遍历扫描表达式指针
    while (infix[i] != '\0') {
        if (infix[i] >= '0' && infix[i] <= '9') {
            result_s.push(infix[i]);
            ++i;
        }
        else if (infix[i] == '(') {
            assist_s.push(infix[i]);
            ++i;
        }
        else if (infix[i] == '+'
                 || infix[i] == '-'
                 || infix[i] == '*'
                 || infix[i] == '/') {
            if (assist_s.is_empty()
                || assist_s.top() == '('
                || priority(infix[i]) > priority(assist_s.top())) {
                assist_s.push(infix[i]);
                ++i;
            }
            else {
                result_s.push(assist_s.top());
                assist_s.pop();
            }
        }
        else if (infix[i] == ')') {
            while (assist_s.top() != '(') {
                result_s.push(assist_s.top());
                assist_s.pop();
            }
            assist_s.pop();
            ++i;
        }
    }
    while (!assist_s.is_empty()) {
        result_s.push(assist_s.top());
        assist_s.pop();
    }
}

/*
 * FunctionName : infixToPrefix()
 * Description : infix expression translate into prefix expression
 * Calls : priority()
 * Parameter 1 : infix expression
 * Parameter 2 : length of infix expression
 * Parameter 3 : result stack
 */
void infixToPrefix(char infix[], const unsigned int& length, Stack<char>& result_s) {
    Stack<char> assist_s;   // assist stack
    int i = length - 1; // log infix[] index 遍历扫描表达式指针
    while (i >= 0) {
        if (infix[i] >= '0' && infix[i] <= '9') {
            result_s.push(infix[i]);
            --i;
        }
        else if (infix[i] == ')') {
            assist_s.push(infix[i]);
            --i;
        }
        else if (infix[i] == '+'
                 || infix[i] == '-'
                 || infix[i] == '*'
                 || infix[i] == '/') {
            if (assist_s.is_empty()
                || assist_s.top() == ')'
                || priority(infix[i]) >= priority(assist_s.top())) {
                assist_s.push(infix[i]);
                --i;
            }
            else {
                result_s.push(assist_s.top());
                assist_s.pop();
            }
        }
        else if (infix[i] == '(') {
            while (assist_s.top() != ')') {
                result_s.push(assist_s.top());
                assist_s.pop();
            }
            assist_s.pop();
            --i;
        }
    }
    while (!assist_s.is_empty()) {
        result_s.push(assist_s.top());
        assist_s.pop();
    }
}


//
// Created by whx on 23-3-1.
//
#ifndef EXPRESSION_CALCULATION_CPP
#define EXPRESSION_CALCULATION_CPP


#include "expression_function.h"

int getPriority(const char& a_operator) {
    if (a_operator == '+' || a_operator == '-') {
        return 0;
    }
    else if (a_operator == '*' || a_operator == '/') {
        return 1;
    }
    else {
        throw invalid_argument("error : the operator is invalid.");
    }
}

double calSub(const double& operand_1, const char& a_operator, const double& operand_2) {
    if (a_operator == '+') {
        return operand_1 + operand_2;
    }
    else if (a_operator == '-') {
        return operand_1 - operand_2;
    }
    else if (a_operator == '*') {
        return operand_1 * operand_2;
    }
    else if (a_operator == '/') {
        if (fabs(operand_2) < MIN) {
            throw invalid_argument("error : the operand is invalid, the divisor is 0");
        }
        else {
            return operand_1 / operand_2;
        }
    }
    else {
        throw invalid_argument("error : the operator is invalid");
    }
}

void calStackTopTwo(Stack<double>& operand_stack, Stack<char>& operator_stack) {
    double left_operand, right_operand;
    char a_operator;
    a_operator = operator_stack.pop();
    right_operand = operand_stack.pop();
    left_operand = operand_stack.pop();
    operand_stack.push(calSub(left_operand, a_operator, right_operand));
}   

double calInfix(char expression[]) {
    Stack<double> operand_stack;
    Stack<char> operator_stack;
    int i = 0;
    while (expression[i] != '\0') {
        if (expression[i] >= '0' && expression[i] <= '9') {
            operand_stack.push(expression[i] - '0');
            ++i;
        }
        else if (expression[i] == '(') {
            operator_stack.push(expression[i]);
            ++i;
        }
        else if (expression[i] == '+'
                || expression[i] == '-'
                || expression[i] == '*'
                || expression[i] == '/') {
            if (operator_stack.is_empty()
                || operator_stack.top() == '('
                || getPriority(expression[i]) > getPriority(operator_stack.top())) {
                operator_stack.push(expression[i]);
                ++i;
            }
            else {
                calStackTopTwo(operand_stack, operator_stack);
            }
        }
        else if (expression[i] == ')') {
            while (operator_stack.top() != '(') {
                calStackTopTwo(operand_stack, operator_stack);
            }
            operator_stack.pop();
            ++i;
        }
    }
    while (!operator_stack.is_empty()) {
        calStackTopTwo(operand_stack, operator_stack);
    }
    return operand_stack.top();
}

double calPostfix(char expression[]) {
    Stack<double> operand_stack;
    for (int i = 0; expression[i] != '\0'; ++i) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            operand_stack.push(expression[i] - '0');
        }
        else {
            double right_operand = operand_stack.pop();
            double left_operand = operand_stack.pop();
            operand_stack.push(calSub(left_operand, expression[i], right_operand));
        }
    }
    return operand_stack.top();
}

double calPrefix(char expression[], const unsigned int& length) {
    Stack<double> operand_stack;
    for (int i = length - 1; i >= 0; --i) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            operand_stack.push(expression[i] - '0');
        }
        else {
            double left_operand = operand_stack.pop();
            double right_operand = operand_stack.pop();
            operand_stack.push(calSub(left_operand, expression[i], right_operand));
        }
    }
    return operand_stack.top();
}


#endif // EXPRESSION_CALCULATION_CPP
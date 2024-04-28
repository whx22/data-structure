//
// Created by whx on 22-11-30.
//

#ifndef CLION_EXPRESSION_FUNCTION_H
#define CLION_EXPRESSION_FUNCTION_H

#include <iostream>
#include <exception>
#include <cmath>
using namespace std;
#include "my_stack.hpp"
#define MIN 0.00001

int priority(const char& a_operator);
void infixToPostfix(char infix[], Stack<char>& result_s);
void infixToPrefix(char infix[], const unsigned int& length, Stack<char>& result_s);
double calSub(const double& operand_1, const char& a_operator, const double& operand_2);
double calInfix(char expression[]);
double calPostfix(char expression[]);
double calPrefix(char expression[], const unsigned int& length);

#endif //CLION_EXPRESSION_FUNCTION_H

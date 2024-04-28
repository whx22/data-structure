//
// Created by whx on 23-3-1.
//

#ifndef PROJECT_EXPRESSION_FUNCTION_H
#define PROJECT_EXPRESSION_FUNCTION_H

#include <iostream>
#include <exception>
#include <cmath>
using namespace std;
#include "stack.cpp"
#include "queue.cpp"
#define MIN 0.00001

/*
 * FunctionName : getPriority()
 * Description : calculate the operator priority
 * Called By : infixToPostfix() && infixToPrefix() && calInfix()
 * Parameter 1 : a operator
 * Return : priority of operator
 */
int getPriority(const char& a_operator);

/*
 * FunctionName : calSub()
 * Description : calculate infix subexpression
 * Called By : calInfix()
 * Parameter 1 : the left operand of subexpression
 * Parameter 2 : the operator of subexpression
 * Parameter 3 : the right operand of subexpression
 * Return : the result of subexpression calculation
 */
double calSub(const double& operand_1, const char& a_operator, const double& operand_2);

/*
 * FunctionName : calStackTopTwo()
 * Description : calculate the top two of operand_stack elements calculate by the top of operator_stack elements
 * Calls : calSub()
 * Parameter 1 : the stack that holds the operands
 * Parameter 2 : the stack that holds the operators
 * Return : (double)the result of the top two of operand_stack elements calculate by the top of operator_stack elements
 */
void calStackTopTwo(Stack<double>& operand_stack, Stack<char>& operator_stack);

/*
 * FunctionName : calInfix()
 * Description : calculate infix expression
 * Calls : getPriority() && calStackTopTwo()
 * Parameter 1 : (char* || string)object infix expression
 * Return : (double)the result of object infix expression calculation
 */
double calInfix(char expression[]);

/*
 * FunctionName : calPostfix()
 * Description : calculate postfix expression
 * Calls : calSub()
 * Parameter : (char* || string)object postfix expression
 * return : the result of object postfix expression calculation
 */
double calPostfix(char expression[]);

/*
 * FunctionName : calPrefix()
 * Description : calculate prefix expression
 * Calls : calSub()
 * Parameter 1 : (char* || string)object prefix expression
 * Parameter 2 : the length of object prefix expression
 * return : the result of object prefix expression calculation
 */
double calPrefix(char expression[], const unsigned int& length);

/*
 * FunctionName : infixToPostfix()
 * Description : infix expression to post expression
 * Calls : getPriority()
 * Parameter 1 : infix expression
 * Parameter 2 : result queue
 */
void infixToPostfix(char infix[], Queue<char>& result_queue);

/*
 * FunctionName : infixToPrefix()
 * Description : infix expression to prefix expression
 * Calls : getPriority()
 * Parameter 1 : infix expression
 * Parameter 2 : length of infix expression
 * Parameter 3 : result stack
 */
void infixToPrefix(char infix[], const unsigned int& length, Stack<char>& result_stack);

/*
 * FunctionName : isMatched()
 * Description : judge two bracket match 
 * Called By : isBracketBalanced()
 * Parameter 1 : right expand
 * Parameter 2 : left expand
 * Return : true || false
 */
bool isMatched(const char& left_bracket, const char& right_bracket);

/*
 * FunctionName : isBracketBalanced()
 * Description : judge the expression' bracket balanced 
 * Calls : isMatched()
 * Parameter : expression[]
 * Return : true || false
 */
bool isBracketBalanced(char expression[]);


#endif // PROJECT_EXPRESSION_FUNCTION_H

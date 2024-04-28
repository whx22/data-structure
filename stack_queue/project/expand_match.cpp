//
// Created by whx on 23-3-2.
//
#ifndef EXPAND_MATCH_CPP
#define EXPAND_MATCH_CPP


#include "expression_function.h"

bool isMatched(const char& left_bracket, const char& right_bracket) {
    if (left_bracket == '(' && right_bracket == ')') {
        return true;
    }
    else if (left_bracket == '[' && right_bracket == ']') {
        return true;
    }
    else if (left_bracket == '{' && right_bracket == '}') {
        return true;
    }
    else {
        return false;
    }
}

bool isBracketBalanced(char expression[]) {
    Stack<char> bracket_stack;
    for (int i = 0; expression[i] != '\0'; ++i) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            bracket_stack.push(expression[i]);
        }
        if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (bracket_stack.is_empty()) {
                return false;
            }
            if(!isMatched(bracket_stack.pop(), expression[i])) {
                return false;
            }
        }
    }
    if (!bracket_stack.is_empty()) {
        return false;
    }
    return true;
}


#endif
// Expand Matching Algorithm

#include <iostream>
#include <exception>
#include "my_stack.hpp"
#include "my_queue.hpp"
using namespace std;

/*
 * FunctionName : isMatched()
 * Description : judge two bracket match 
 * Called By : isBracketBalanced()
 * Parameter 1 : right expand
 * Parameter 2 : left expand
 * Return : true || false
 */
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

/*
 * FunctionName : isBracketBalanced()
 * Description : judge the expression' bracket balanced 
 * Calls : isMatched()
 * Parameter : expression[]
 * Return : true || false
 */
bool isBracketBalanced(char expression[]) {
    Stack<char> bracket_S;
    for (int i = 0; expression[i] != '\0'; ++i) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            bracket_S.push(expression[i]);
        }
        if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (bracket_S.is_empty()) {
                return false;
            }
            else {
                char left_bracket = bracket_S.pop();
                if (!isMatched(left_bracket, expression[i])) {
                    return false;
                }
            }
        }
    }
    if (!bracket_S.is_empty()) {
        return false;
    }
    return true;
}

int main(void) {

}
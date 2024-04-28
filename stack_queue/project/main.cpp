#include <iostream>
#include <cstring>
#include "stack.cpp"
#include "queue.cpp"
#include "expression_function.h"
using namespace std;

// the code test stack
void test_1(void) {
    char array[6] = "abcde";
    Stack<char> stack;
    for (int i = 0; i < 6; ++i) {
        stack.push(array[i]);
    }
    cout << "the out stack sequence is : " << endl;
    for (int i = 0; i < 6; ++i) {
        cout << stack.pop() << '\t';
    }
    cout << endl;
}

// the code test expression calculate
void test_2(void) {
    char infix_expression_1[] = "(1+2)*3+4-(5+6)*7";
    cout << "the result of calculate of infix expression is : " << calInfix(infix_expression_1) << endl;
    char postfix_expression_1[] = "12+3*4+56+7*-";
    cout << "the result of calculate of postfix expression is : " << calPostfix(postfix_expression_1) << endl;
    char prefix_expression[] = "-+*+1234*+567";
    int prefix_length = strlen(prefix_expression);
    cout << "the result of calculate of prefix_expression is : " << calPrefix(prefix_expression, prefix_length) << endl;
}

// the code test expression conversion
void test_3(void) {
    char infix_expression_1[] = "(1+2)*3+4-(5+6)*7";

    Queue<char> postfix_result_queue;
    infixToPostfix(infix_expression_1, postfix_result_queue);
    cout << "the result postfix expression is : ";
    while (!postfix_result_queue.is_empty()) {
        cout << postfix_result_queue.exit();
    }
    cout << endl;

    Stack<char> prefix_result_stack;
    int infix_length = strlen(infix_expression_1);
    infixToPrefix(infix_expression_1, infix_length, prefix_result_stack);
    cout << "the result prefix expression is : ";
    while (!prefix_result_stack.is_empty()) {
        cout << prefix_result_stack.pop();
    }
    cout << endl;
}

void test_4(void) {
    char expression_1[] = "(1+2)*3+4-(5+6)*7";
    if (isBracketBalanced(expression_1)) {
        cout << "the expression bracket is balance" << endl;
    }
    else {
        cout << "the expression bracket is not balance" << endl;
    }
}

int main() {
    // test_1();
    // test_2();
    // test_3();
    test_4();
    return EXIT_SUCCESS;
}

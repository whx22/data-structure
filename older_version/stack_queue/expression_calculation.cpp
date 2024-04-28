/*
 * expression_calculation
 * 用栈实现表达式求值(Use the Stack to Implement Expression Calculation)
 */

#include "expression_function.h"

/*
 * FunctionName : calSub()
 * Description : calculate infix subexpression
 * Called By : calInfix()
 * Parameter 1 : the left operand of subexpression
 * Parameter 2 : the operator of subexpression
 * Parameter 3 : the right operand of subexpression
 * Return : the result of subexpression calculation
 */
double calSub(const double& operand_1, const char& a_operator, const double& operand_2) {
    if (a_operator == '+') { return operand_1 + operand_2; }
    if (a_operator == '-') { return operand_1 - operand_2; }
    if (a_operator == '*') { return operand_1 * operand_2; }
    if (a_operator == '/') {
        if (fabs(operand_2) < MIN) {
            throw invalid_argument("error : the operand is invalid, divisor is 0");
        }
        else {
            return operand_1 / operand_2;
        }
    }
    else {
        cerr << "error : the operator is invalid" << endl;
        exit(EXIT_FAILURE);
    }
}

/*
 * FunctionName : calInfix()
 * Description : calculate infix expression
 * Calls : priority() && calSub()
 * Parameter 1 : (char* || string)object infix expression
 * Return : (double)the result of object infix expression calculation
 */
double calInfix(char expression[]) {
    Stack<double> operand_S;// value stack : stored operand
    Stack<char> operator_S; // operator stack : store operator
    int i = 0;  // log expression[] index 遍历扫描表达式指针
    while (expression[i] != '\0') {
        if (expression[i] >= '0' && expression[i] <= '9') {
            operand_S.push(expression[i] - '0'); // calculate the number char's value
            ++i;
        }
        else if (expression[i] == '(') {
            operator_S.push(expression[i]);
            ++i;
        }
        else if (expression[i] == '+'
                || expression[i] == '-'
                || expression[i] == '*'
                || expression[i] == '/') {
            if (operator_S.is_empty()
                || operator_S.top() == '('
                || priority(expression[i]) > priority(operator_S.top())) {
                operator_S.push(expression[i]);
                ++i;
            }
            else {
                double left_operand, right_operand, result;
                char a_operator;
                a_operator = operator_S.pop();
                // notice sequence :
                // right operand is first pop stack
                // left operand is last pop stack
                right_operand = operand_S.pop();
                left_operand = operand_S.pop();
                try {
                    result = calSub(left_operand, a_operator, right_operand);
                }
                catch (const exception& e) {
                    cerr << e.what() << endl;
                }
                operand_S.push(result);
            }
        }
        else if (expression[i] == ')') {
            while (operator_S.top() != '(') {
                double left_operand, right_operand, result;
                char a_operator;
                a_operator = operator_S.pop();
                // notice sequence :
                // right operand is first pop stack
                // left operand is last pop stack
                right_operand = operand_S.pop();
                left_operand = operand_S.pop();
                try {
                    result = calSub(left_operand, a_operator, right_operand);
                }
                catch (const exception& e) {
                    cerr << e.what() << endl;
                }
                operand_S.push(result);
            }
            operator_S.pop(); // pop '('
            ++i;
        }
    }
    while (!operator_S.is_empty()) {
        double left_operand, right_operand, result;
        char a_operator;
        a_operator = operator_S.pop();
        // notice sequence :
        // right operand is first pop stack
        // left operand is last pop stack
        right_operand = operand_S.pop();
        left_operand = operand_S.pop();
        try {
            result = calSub(left_operand, a_operator, right_operand);
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }
        operand_S.push(result);
    }
    return operand_S.top(); // the last result stored at operand stack top
}

/*
 * FunctionName : calPostfix()
 * Description : calculate postfix expression
 * Calls : calSub()
 * Parameter : (char* || string)object postfix expression
 * return : the result of object postfix expression calculation
 */
double calPostfix(char expression[]) {
    Stack<double> operand_S; // operand stack : stored operand
    for (int i = 0; expression[i] != '\0'; ++i) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            operand_S.push(expression[i] - '0');
        }
        else if (expression[i] == '+'
                || expression[i] == '-'
                || expression[i] == '*'
                || expression[i] == '/') {
            // notice sequence :
            // right operand is first pop stack
            // left operand is last pop stack
            double right_operand = operand_S.pop();
            double left_operand = operand_S.pop();
            double result = calSub(left_operand, expression[i], right_operand);
            operand_S.push(result);
        }
        else {
            cerr << "error : the postfix is invalid" << endl;
            exit(EXIT_FAILURE);
        }
    }
    return operand_S.top();
}

/*
 * FunctionName : calPrefix()
 * Description : calculate prefix expression
 * Calls : calSub()
 * Parameter 1 : (char* || string)object prefix expression
 * Parameter 2 : the length of object prefix expression
 * return : the result of object prefix expression calculation
 */
double calPrefix(char expression[], const unsigned int& length) {
    Stack<double> operand_S; // operand stack : stored operand
    for (int i = length - 1; i >= 0; --i) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            operand_S.push(expression[i] - '0');
        }
        else if (expression[i] == '+'
                || expression[i] == '-'
                || expression[i] == '*'
                || expression[i] == '/') {
            // notice sequence :
            // left operand is first pop stack
            // right operand is last pop stack
            double left_operand = operand_S.pop();
            double right_operand = operand_S.pop();
            double result = calSub(left_operand, expression[i], right_operand);
            operand_S.push(result);
        }
        else {
            cerr << "error : the postfix is invalid" << endl;
            exit(EXIT_FAILURE);
        }
    } 
    return operand_S.top();
}

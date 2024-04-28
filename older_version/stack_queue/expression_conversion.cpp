/*
 * expression_conversion
 * 用栈实现表达式转换(Use the Stack to Implement Expression Conversion)
 * 
 * 中缀表达式(Infix Expression)
 * 前缀表达式、(Prefix Expression) 波兰表达式(Polish Expression)
 * 后缀表达式(Postfix Expression) 逆波兰表达式(Reverse Polish Expression)
 * 
 * 1、中缀表达式->后缀表达式
 * 2、中缀表达式->前缀表达式
 */

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
        cerr << "error : argument operator is invalid" << endl;
        exit(EXIT_FAILURE);
    }
}

/* 
 * 1、中缀表达式->后缀表达式
 * Description of the process:
 * 从前向后 扫描中缀表达式，每一个 if分支 注意都要对遍历扫描指针 (++i)
 * if 为 number 
 *      push result_stack;
 * if 为 '(' 
 *      push assist_stack;
 * if 为 operator('+'、'-'、'*'、'/') 进行判断
 *      if (assist_stack is empty ||     // 栈空
 *          assist_stack.top is '(' ||   // 栈顶元素为'(' 
 *          priority (this->operator > assist.top.operator)    //优先级 > 
 *         )
 *          push assist_stack;
 *      else //优先级 <= ：当前扫描的operator的优先级 小于或等于 辅助栈栈顶的operator的优先级  
 *      // 注意当前 分支 不能 (++i) 原因：当前 i 指向为operator待处理
 *          pop assist_stack.top to push result_stack.top;
 * if 为 ')'
 *      一直 pop assist_stack.top to push result_stack.top; 到 assist_stack.top 为 '('
 *      pop assist_stack.top(为'(')
 * 
 * 扫描结束，assist_stack 不为空，将辅助栈中的剩余元素依次 pop 并且 push 入 result_stack 中 
 *      pop assist_stack.top to push result_stack.top;
 *   
 */

/*
 * FunctionName : infixToPostfix()
 * Description : infix expression to post expression
 * Calls : priority()
 * Parameter 1 : infix expression
 * Parameter 2 : result stack
 */
void infixToPostfix(char infix[], Stack<char>& result_s) {
    Stack<char> assist_s;   // assist stack
    int i = 0;              // log infix[] index 遍历扫描表达式指针
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
 * 2、中缀表达式->前缀表达式
 * Description of the process:
 * 从后向前 扫描中缀表达式，每一个 if分支 注意都要对遍历扫描指针 (--i)
 * if 为 number 
 *      push result_stack;
 * if 为 ')' 
 *      push assist_stack;
 * if 为 operator('+'、'-'、'*'、'/') 进行判断
 *      if (assist_stack is empty ||     // 栈空
 *          assist_stack.top is ')' ||   // 栈顶元素为')' 
 *          priority (this->operator >= assist.top.operator)    //优先级 >= 
 *         )
 *          push assist_stack;
 *      else //优先级 < ：当前扫描的operator的优先级 小于或等于 辅助栈栈顶的operator的优先级  
 *      // 注意当前 分支 不能 (--i) 原因：当前 i 指向为operator待处理
 *          pop assist_stack.top to push result_stack.top;
 * if 为 '('
 *      一直 pop assist_stack.top to push result_stack.top; 到 assist_stack.top 为 ')'
 *      pop assist_stack.top(为')')
 * 
 * 扫描结束，assist_stack 不为空，将辅助栈中的剩余元素依次 pop 并且 push 入 result_stack 中 
 *      pop assist_stack.top to push result_stack.top;
 */

/*
 * FunctionName : infixToPrefix()
 * Description : infix expression to prefix expression
 * Calls : priority()
 * Parameter 1 : infix expression
 * Parameter 2 : length of infix expression
 * Parameter 3 : result stack
 */
void infixToPrefix(char infix[], const unsigned int& length, Stack<char>& result_s) {
    Stack<char> assist_s;   // assist stack
    int i = length - 1;     // log infix[] index 遍历扫描表达式指针
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
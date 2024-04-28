/*
 * 根据中缀表达式建立一个表达式树
 * 所建立的表达式树
 * 先序遍历结果 : 前缀表达式(波兰式)
 * 后序遍历结果 : 后缀表达式(逆波兰式)
*/
#include <iostream>
#include <exception>
#include <cmath>
using namespace std;
#define MIN 0.00001

typedef struct BTNode {
    char data;
    struct BTNode* lChild;
    struct BTNode* rChild;
} BTNode; 
typedef BTNode* BinaryTree;

// TOTO : 使用栈根据中缀表达式建立表达式树

double calSub(const double& operand_1, const char& a_operator, \
                const double& operand_2) {
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

// 根据表达式树计算表达式的结果
double calculate_expression_tree(const BinaryTree& root) {
    if (root->lChild == nullptr && root->rChild == nullptr) {
        return root->data - '0';
    }
    else {
        double operand_1 = calculate_expression_tree(root->lChild);
        double operand_2 = calculate_expression_tree(root->rChild);
        return calSub(operand_1, root->data, operand_2);
    }
}
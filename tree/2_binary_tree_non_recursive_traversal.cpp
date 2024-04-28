// binary tree non-recursive traversal
#include <iostream>
using namespace std;
#include "my_stack.hpp"

typedef struct BTNode {
    int data;
    struct BTNode* lChild;
    struct BTNode* rChild; 
} BTNode;
typedef BTNode* BinaryTree;

void visit(const BinaryTree& bt) {
    cout << bt->data << endl;
}

/* FunctionName : 先序遍历非递归化
 * Description : 从根结点开始, 入栈一个结点, 如果栈不空, 出栈一个元素并访问, 如果出栈元素存在左右孩子, 则入栈(入栈顺序 : 先右孩子, 后左孩子), 如果栈空, 遍历函数结束 
 */
void preorderNonRecursive(const BinaryTree& bt) {
    if (bt != nullptr) {
        Stack<BinaryTree> assist_stack;
        BTNode* p = nullptr;
        assist_stack.push(bt);
        while (!assist_stack.is_empty()) {
            p = assist_stack.pop();
            visit(p);
            if (p->rChild != nullptr) {
                assist_stack.push(p->rChild);
            }
            if (p->lChild != nullptr) {
                assist_stack.push(p->lChild);
            }
        }
    }
}

/* FunctionName : 后序遍历非递归化
 * Method : 
 * 先序遍历顺序 : 根 -> 左子树 -> 右子树
 * 后序遍历顺序 : 左子树 -> 右子树 -> 根
 * 逆后序遍历顺序 : 根 -> 右子树 -> 左子树
 * Description : 改变先序遍历非递归化方法入栈左右子树顺序, 用栈存储得到的逆后序遍历, 再依次出栈, 得到后序遍历. 
 */ 
void postorderNonRecursive(const BinaryTree& bt) {
    if (bt != nullptr) {
        Stack<BinaryTree> assist_stack;
        Stack<BinaryTree> result_stack;
        BTNode* p = nullptr;
        assist_stack.push(bt);
        while (!assist_stack.is_empty()) {
            p = assist_stack.pop();
            result_stack.push(p);
            if (p->lChild != nullptr) {
                assist_stack.push(p->lChild);
            }
            if (p->rChild != nullptr) {
                assist_stack.push(p->rChild);
            }
        }
        while (!result_stack.is_empty()) {
            visit(result_stack.pop());
        }
    }
}

/* FunctionName : 中序遍历非递归化
 * Description : 从根开始, 一直入栈二叉树的左子树, 知道左子树为空, 
 * 出栈一个元素并访问, 并对出栈元素其右孩子做以上重复动作
 */
void middleOrderNonRecursive(const BinaryTree& bt) {
    if (bt != nullptr) {
        Stack<BinaryTree> assist_stack;
        BTNode* p = bt;
        while (!assist_stack.is_empty() || p != nullptr) {
            while (p != nullptr) {
                assist_stack.push(p);   
                p = p->lChild;
            }
            p = assist_stack.pop();
            visit(p);
            p = p->rChild;
        }
    }
}
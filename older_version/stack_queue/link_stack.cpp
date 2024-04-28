/*
 * Link List Stack
 */

#include <iostream>
#include <exception>
using namespace std;

typedef struct LinkNode {
    int data;
    struct LinkNode* next;
} LinkNode;
typedef LinkNode* LinkList;

typedef struct {
    LinkList head;
    LinkNode* top;
} Stack;

// Initialize Link List Stack
void initLinkListStack(Stack& stack) {
    stack.head = new LinkNode;
    stack.head->next = nullptr;
    stack.top = nullptr;
}

/*
 * Push Link List Stack
 * description : 压栈时，使用头插法，top始终指向新插入的节点 (top == head->next)
 */ 
void pushLinkListStack(Stack& stack,const int& element) {     
    stack.top = new LinkNode;
    stack.top->data = element;
    // stack.top->next = nullptr;
    stack.top->next = stack.head->next;
    stack.head->next = stack.top;
}

// Pop Link List Stack
void popLinkListStack(Stack& stack, int& element) {
    if (stack.head->next == nullptr) {
        throw out_of_range("error : the stack is empty");
    }
    element = stack.top->data;
    stack.head->next = stack.top->next;
    delete stack.top;
    stack.top = stack.head->next;
}
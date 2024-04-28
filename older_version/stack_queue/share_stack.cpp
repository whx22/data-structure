/*  
 * share stack 
 */

#include <iostream>
#include <exception>
using namespace std;

#define MAXSIZE 100

typedef struct {
    int data[MAXSIZE];
    int top[2] = {-1, MAXSIZE};
} ShareStack;

// Initialize ShareStack
void InitShareStack(ShareStack& share_stack) {
    share_stack.top[0] = -1;
    share_stack.top[1] = MAXSIZE;
}

// is_empty ShareStack
bool is_empty(ShareStack& share_stack) {
    if (share_stack.top[0] == -1 && share_stack.top[1] == MAXSIZE) {
        return true;
    }
    else {
        return false;
    }
}

// is_full ShareStack
bool is_full(ShareStack& share_stack) {
    if (share_stack.top[0] + 1 == share_stack.top[1]) {
        return true;
    }
    else {
        return false;
    }
}
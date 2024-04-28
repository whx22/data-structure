// create binary tree by traversal sequence
#include <iostream>
using namespace std;

typedef struct BTNode {
    char data;
    struct BTNode* lChild;
    struct BTNode* rChild;
} BTNode; 
typedef BTNode* BinaryTree;

// 通过先序遍历序列和中序遍历序列确定并构造二叉树
/*
 * FunctionName : createBinaryTree_1()
 * Description : create binary tree by pre-traversal sequence and in-traversal sequence 
 * Parameter 1 : pre-traversal sequence
 * Parameter 2 : in-traversal sequence 
 * Parameter 3 : pre-traversal sequence subTree begin index 
 * Parameter 4 : pre-traversal sequence subTree end index
 * Parameter 5 : in-traversal sequence subTree begin index
 * Parameter 6 : in-traversal sequence subTree end index
 */
BinaryTree createBinaryTree_1 (const char* pre, const char* in, \ 
                                const int& L1, const int& R1, \
                                const int& L2, const int& R2) {
    if (L1 > R1) {
        return nullptr;
    }
    BTNode* r = new BTNode;
    r->lChild = r->rChild = nullptr;
    r->data = pre[L1];

    int i;
    for (i = L2; i < R2; ++i) {
        if (in[i] == pre[L1]) {
            break;
        }
    }

    r->lChild = createBinaryTree_1(pre, in, L1 + 1, L1 + i - L2, L2, i - 1);
    r->rChild = createBinaryTree_1(pre, in, L1 + i - L2 + 1, R1, i + 1, R2);
    return r;
}

// 通过后序遍历序列和中序遍历序列确定并构造二叉树
/*
 * FunctionName : createBinaryTree_1()
 * Description : create binary tree by pre-traversal sequence and in-traversal sequence 
 * Parameter 1 : pre-traversal sequence
 * Parameter 2 : in-traversal sequence 
 * Parameter 3 : pre-traversal sequence subTree begin index 
 * Parameter 4 : pre-traversal sequence subTree end index
 * Parameter 5 : in-traversal sequence subTree begin index
 * Parameter 6 : in-traversal sequence subTree end index
 */
BinaryTree createBinaryTree_2(const char* post, const char* in, \ 
                                const int& L1, const int& R1, \
                                const int& L2, const int& R2) {
    if (L1 > R1) {
        return nullptr;
    }
    BTNode* r = new BTNode;
    r->lChild = r->rChild = nullptr;
    r->data = post[R1];

    int i;
    for (i = L2; i < R2; ++i) {
        if (in[i] == post[R1]) {
            break;
        }
    }
    r->lChild = createBinaryTree_2(post, in, L1, L1 + i - L2 - 1, L2, i - 1);
    r->rChild = createBinaryTree_2(post, in, L1 + i - L2, R1 - 1, i + 1, R2);

    return r;
}

// 通过层次遍历序列和中序遍历序列确定并构造二叉树
int search(const char* arr, const char& key, const int& L, const int& R) {
    int index;
    for (index = L; index <= R; ++index) {
        if (arr[index] == key) {
            return index;
        }
    }
    return -1;
}

void getSubLevel(char* subLevel, const char* level, const char* in, \
                    const int& n, const int& L, const int& R) {
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (search(in, level[i], L, R) != -1) {
            subLevel[k++] = level[i];
        }
    }
}

BinaryTree createBinaryTree_3(const char* level, const char* in, \
                                int n, int L, int R) {
    if (L > R) {
        return nullptr;
    }
    BTNode* r = new BTNode;
    r->lChild = r->rChild = nullptr;
    r->data = level[0];

    int i = search(in, level[0], L, R);
    int LN = i - L; char LLevel[LN];
    int RN = R - i; char RLevel[RN];

    getSubLevel(LLevel, level, in, n, L, i - 1);
    getSubLevel(RLevel, level, in, n, i + 1, R);

    r->lChild = createBinaryTree_3(LLevel, in, LN, L, i - 1);
    r->rChild = createBinaryTree_3(RLevel, in, RN, i + 1, R);

    return r;
}
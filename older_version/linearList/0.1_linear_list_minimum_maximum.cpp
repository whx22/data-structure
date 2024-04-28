// Find the Minimum and Maximum of Linear List

#include <iostream>
using namespace std;

// In Sequential List

int SeqListMinimum(int arr[], int length) {
    int min = arr[0];
    int minIndex = 0;
    for (int i = 0; i < length; ++i) {
        if (min > arr[i]) {
            min = arr[i];
            minIndex = i;
        }
    }
    return min;     // return minimum
    return minIndex;// return the index of minimum
}

int SeqListMaximum(int arr[], int length) {
    int max = arr[0];
    int maxIndex = 0;
    for (int i = 0; i < length; ++i) {
        if (max < arr[i]) {
            max = arr[i];
            maxIndex = i;
        }
    }
    return max;     // return maximum
    return maxIndex;// return the index of maximum
}

// In Link List 

typedef struct LinkNode {
    int data;
    struct LinkNode* next;
} LinkNode;

typedef LinkNode* LinkList;

int LinkListMinimum(const LinkList& head) {
    LinkNode* p = nullptr;  // 遍历指针
    LinkNode* q = nullptr;  // 维护minimum节点指针
    int min = head->next->data;
    p = q = head->next;
    while (p != nullptr) {
        if (min > p->data) {
            min = p->data;
            q = p;
        }
        p = p->next;
    }
    return min; // return minimum
    // return q;    // return a pointer of the minimum data node
}

int LinkListMaximum(const LinkList& head) {
    LinkNode* p = nullptr;  // 遍历指针
    LinkNode* q = nullptr;  // 维护maximum节点指针
    int max = head->next->data;
    p = q = head->next;
    while (p != nullptr) {
        if (max < p->data) {
            max = p->data;
            q = p; 
        }
        p = p->next;
    }
    return max; // return maximum
    // return q;    // return the pointer of the maximum data node
}
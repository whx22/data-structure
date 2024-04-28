#include <iostream>
using namespace std;

// 顺序表逆置
void reverseArray(int array[], int length) {    
    int temp = 0;
    for (int i = 0, j = length - 1; i < j; ++i, --j) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// 链表逆置
// 部分逆置 : 逆置p结点到q结点之间的结点
typedef struct LNode {
    int             data;
    struct LNode*   next;
} LNode;
typedef struct LinkList;

void reverseLinkList(LinkList& head, LNode* p, LNode* q) {
    LNode* t = nullptr;
    while (p->next != q) {
        t = p->next;
        p->next = t->next;
        t->next = q->next;
        q->next = t;
    }
}

// 1.将一长度为n的数组的前端k(k < n)个元素逆序后移动到数组后端, 要求原数组中数据不丢失;
void reverse(int array[], int left, int right, int k) {
    int temp;
    for (int i = left, j = right; i < left + k && i < j; ++i, --j) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// 2.将一长度为n的数组的前端k(k < n)个元素保持原序后移动到数组后端, 要求原数组中数据不丢失;
void moveToEnd(int array[], int n, int k) {
    reverse(array, 0, k - 1, k);
    reverse(array, 0, n - 1, k);
}

// 真题 : 将长度为n的数组保存序列循环左移p个位置
void moveP(int array[], int n, int p) {
    reverse(array, 0, p - 1, p);
    reverse(array, p, n - 1, n - p);
    reverse(array, 0, n - 1, n);
}

int main(void) {

    return EXIT_SUCCESS;
}
#include <iostream>
using namespace std;

// 1.带头结点单链表逆置链表
typedef struct LNode {
    int data;
    struct LNode* next;
} LNode;
typedef LNode* LinkList;

void reverse(LinkList head) {
    LNode* p = head->next;
    LNode* q = nullptr;
    head->next = nullptr;
    while (p != nullptr) {
        q = p->next;
        p->next = head->next;
        head->next = p;
        p = q;
    }
}

// 2.仅使用一个变量, 找到个位正整数顺序表中的最大值
int maxOfArray(int array[], int length) {
    int i = 0;
    while (i / 10 < length) {
        if (i % 10 < array[i / 10]) {
            i -= i % 10;
            i += array[i / 10];
        }
        i += 10;
    }
    return i % 10;
}

// 3.逆序打印带头结点单链表(递归)
// 分治法 : 将可划分的大问题分解为小问题
void reprint(LinkList head) {
    if (head != nullptr) {
        reprint(head->next);
        cout << head->data << '\t';
    }
}

// 4.判断两个有序链表是否相等.
bool isEqual(LinkList A, LinkList B) {
    LNode* p = A->next;
    LNode* q = B->next;
    while (p != nullptr && q != nullptr) {
        if (p->data == q->data) {
            p = p->next;
            q = q->next;
        } else {
            return false;
        }
    }
    if (p != nullptr || q != nullptr) {
        return false;
    } else {
        return true;
    }
}

int main(void) {

    return EXIT_SUCCESS;
}
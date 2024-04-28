#include <iostream>
using namespace std;
#define MAXSIZE 100

// 顺序表中插入一个元素
void insertElem(int seqList[], int& length, const int& index, const int& elem) {
    if (index < 0 || index > length || length >= MAXSIZE) {
        throw invalid_argument("error : invalid argument");
    } else {
        for (int i = 0; i < length - index; ++i) {
            seqList[length - i] = seqList[length - i - 1];
        }
        seqList[index] = elem;
        ++length; 
    }
}

// 顺序表中删除一个元素
void deleteElem(int seqList[], int& length, const int& index, int& elem) {
    if (index < 0 || index > length - 1) {
        throw invalid_argument("error : invalid argument");
    }
    elem = seqList[index];
    for (int i = 0; i < length - index - 1; ++i) {
        seqList[index + i] = seqList[index + i + 1];
    }
    --length;    
}

// 顺序表中删除index i ~ j 位置的元素
void delete_i_j_Elem(int seqList[], int& length, const int& i, const int& j) {
    if (i < 0 || j - i + 1 > length) {
        throw invalid_argument("error : invalid argument");
    }
    for (int k = 0; k < length - j; ++k) {
        seqList[i + k] = seqList[j + 1 + k];
    }
    length -= j - i + 1;
}

// 顺序表打印
void printSeqList(int seqList[], int length) {
    for (int i = 0; i < length; ++i) {
        cout << seqList[i] << '\t';
    }
    cout << endl;
}

void test_1(void) {
int seqList[MAXSIZE] = { 1, 2, 3, 4, 5, 6 };
int length = 6;
    printSeqList(seqList, length);
int elem;
    deleteElem(seqList, length, 2, elem);
    printSeqList(seqList, length);
    insertElem(seqList, length, 2, elem);
    printSeqList(seqList, length);
    delete_i_j_Elem(seqList, length, 0, 1);
    printSeqList(seqList, length);
}

typedef struct LNode {
    int             data;
    struct LNode*   next;
} LNode;
typedef LNode* LinkList;

// 带头结点单链表建立
void createLinkList(LinkList& head, int array[], int n) {
    head = new LNode;
    head->next = nullptr;
    LNode* r = head;
    for (int i = 0; i < n; ++i) {
        LNode* p = new LNode;
        p->data = array[i];
        p->next = nullptr;
        r->next = p;
        r = p;
    }
}

void printLinkList(LinkList head) {
    LNode* p = head->next;
    while (p != nullptr) {
        cout << p->data << '\t';
        p = p->next;
    }
    cout << endl;
}

// 删除非递减单链表中的重复结点
void deleteLinkListRepeat(LinkList& head) {
    LNode* p = head->next;
    LNode* q = nullptr;
    while (p->next != nullptr) {
        if (p->data == p->next->data) {
            q = p->next;
            p->next = q->next;
            free(q);
        } else {
            p = p->next;
        }
    }
}

void test_2(void) {
int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int length = 10;
LinkList head;
    createLinkList(head, array, length);
    printLinkList(head);
    deleteLinkListRepeat(head);
    printLinkList(head);
}

// 将带头结点单链表A分为, 一个只含奇数A', 一个只含偶数B 带头结点的单链表, 并保持原来的顺序
void splitLinkList(LinkList& A, LinkList& B) {
    B = new LNode;
    B->next = nullptr;
    LNode* p = A;
    LNode* r = B;
    LNode* q = nullptr;
    while (p->next != nullptr) {
        if (p->next->data % 2 == 0) {
            q = p->next;
            p->next = p->next->next;
            q->next = nullptr;
            r->next = q;
            r = q;
        } else {
            p = p->next;
        }
    }
}


int main(void) {
    test_2();
    return EXIT_SUCCESS;
}
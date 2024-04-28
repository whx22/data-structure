// Merge Linear List

#include <iostream>
using namespace std;

// Merge Sequential List
void mergeArr(int A[], int length_A, int B[], int length_B, int C[]) {
    int i = 0, j = 0;
    int k = 0;
    while (i < length_A && j < length_B) {
        if (A[i] < B[j]) {
            C[k++] = A[i++];
        }
        else {
            C[k++] = B[j++];
        }
    }
    while (i < length_A) {
        C[k++] = A[i++];
    }
    while (j < length_B) {
        C[k++] = B[j++];
    }
}

void test(void) {
    int A[4] = {1, 3, 6, 7};
    int B[5] = {3, 5, 8, 9, 10};
    int C[9];
    mergeArr(A, 4, B, 5, C);

    for (int i = 0; i < 9; ++i) {
        cout << C[i] << endl;
    }
}

// Merge Link List
typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode;

// 头插法   
void CreateLinkListH(LinkNode *&head) {
    head = new LinkNode;
    head->next = nullptr;
    LinkNode *p = nullptr;
    int n;
    int num;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        p = new LinkNode;
        p->next = nullptr;
        cin >> num;
        p->data = num;
        p->next = head->next;
        head->next = p;  
    }
}

// 尾插法
void CreatLinkListR(LinkNode *&head) {
    head = new LinkNode;
    head->next = nullptr;
    LinkNode *r = head;
    LinkNode *p = nullptr;
    int n;
    int num;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        p = new LinkNode;
        p->data = num;
        p->next = r->next;
        r->next = p;
        r = p;
    }
}

void printLinkList(LinkNode *head) {
    LinkNode *p = head->next;
    while (p != nullptr) {
        cout << p->data << endl;
        p = p->next;
    }
}

// 顺序归并first
void mergeLinkList(LinkNode *&a, LinkNode *&b) {
    LinkNode *p = a->next;
    LinkNode *q = b->next;
    LinkNode *r = a;

    while (p != nullptr && q != nullptr) {
        if (p->data < q->data) {
            r->next = p;
            r = p;
            p = p->next;
        }
        else {
            r->next = q;
            r = q;
            q = q->next;
        }
    }

    if (q == nullptr) {
        r->next = p;
    }

    if (p == nullptr) {
        r->next = q;
    }
}

// 顺序归并second
void mergeLinkList(LinkNode *A, LinkNode *B, LinkNode *&C) {
    LinkNode *p = A->next;
    LinkNode *q = B->next;
    C = A;
    delete B;
    LinkNode *r = C;
    while (p != nullptr && q != nullptr) {
        if (p->data < q->data) {
            r->next = p;
            r = r->next;
            p = p->next;
        }
        else {
            r->next = q;
            r = q;
            q = q->next;
        }
    }

    if (p != nullptr) {
        r->next = p;
    }
    if (q != nullptr) {
        r->next = q;
    }
}

// 逆序归并
void mergeLinkListReverse(LinkNode *A, LinkNode *B, LinkNode *&C) {
    LinkNode *p = A->next;
    LinkNode *q = B->next;
    LinkNode *s = nullptr;
    C = A;
    C->next = nullptr;
    delete B;
    
    while (p != nullptr && q != nullptr) {
        if (p->data < q->data) {
            s = p;
            p = p->next;
            s->next = C->next;
            C->next = s;
        }
        else {
            // 注意：先改变q指向，在对将该节点链接到C链表中
            // 原因：q与s指向同一内存空间
            s = q;
            q = q->next;    
            s->next = C->next;
            C->next = s;
        }
    }
    while (p != nullptr) {
        s = p;
        p = p->next;
        s->next = C->next;
        C->next = s;
    }
    while (q != nullptr) {
        s = q;
        q = q->next;
        s->next = C->next;
        C->next = s;
    }
}

void test_2(void) {
    LinkNode *a = nullptr;
    CreatLinkListR(a);
    LinkNode *b = nullptr;
    CreatLinkListR(b);
    cout << "a = " << endl;
    printLinkList(a);
    cout << "b = " << endl;
    printLinkList(b);

    LinkNode *c = nullptr;
    mergeLinkListReverse(a, b, c);
    cout << "after merge" << endl;
    printLinkList(a); 
}

int main(void) {
    test_2();
    return EXIT_SUCCESS;
}
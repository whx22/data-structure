#include "base.h"

Status InitLinkList(LinkList &L);
void CreatListTail(LinkList &L, int n);
// void _print(LinkList L);
LinkList MergeLinkList(LinkList &A, LinkList &B);
LinkList MergeList_L(LinkList &A, LinkList &B);
Status ListOppose(LinkList &L);

int main(void) {
    int m, n;
    char ch;
    printf("请您输入开始时递增有序的单链表A中有多少个元素：");
    while (scanf("%d", &m) != 1) {
        while (ch = getchar() != '\n') {
            putchar(ch);
            printf("不是合法输入。\n请再次输入：");
        }
    }
    LinkList A;
    InitLinkList(A);
    CreatListTail(A, m);

    printf("请您输入开始时递增有序的单链表B中有多少个元素：");
    while (scanf("%d", &n) != 1) {
        while (ch = getchar() != '\n') {
            putchar(ch);
            printf("不是合法输入。\n请再次输入：");
        }
    }

    LinkList(B);
    InitLinkList(B);
    CreatListTail(B, n);

    printf("递增有序的单链表A中的元素依次为：（  ");
    if (A->next != NULL) {
        LNode *print = A->next;
        while (print != NULL) {
            printf("%d  ", print->data);
            print = print->next;
        }
    }
    printf("）\n");

    printf("递增有序的单链表B中的元素依次为：（  ");
    if (B->next != NULL) {
        LNode *print = B->next;
        while (print != NULL) {
            printf("%d  ", print->data);
            print = print->next;
        }
    }
    printf("）\n");

    // A = MergeList_L(A, B);
    // ListOppose(A);
    A = MergeLinkList(A, B);

    printf("A、B表合并后形成的递减有序的单链表C中的元素依次为：（  ");
    if (A->next != NULL) {
        LNode *print = A->next;
        while (print != NULL) {
            printf("%d  ", print->data);
            print = print->next;
        }
    }
    printf("）\n");

    return 0;
}

//带头结点的单链表初始化
Status InitLinkList(LinkList &L) {
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    return OK;
}

//尾插法建立带头结点的单链表（条件：L已存在）
void CreatListTail(LinkList &L, int n) {
    srand(time(NULL));
    int num = 0;
    LNode *r = L; // r恒指向尾结点（r为尾指针）
    for (int i = 0; i < n; i++) {
        LNode *p = (LNode *)malloc(sizeof(LNode));
        num += rand() % 20 + 1;
        p->data = num;
        r->next = p;
        r = p;
    }
    r->next = NULL; //创建结束，尾结点的指针域指向NULL
}

//头插法依次插入最小值
LinkList MergeLinkList(LinkList &A, LinkList &B) {
    LNode *p1 = A->next;
    A->next = NULL; //选择A作为结果链表的头指针，先将结果链表初始化为空
    LNode *p2 = B->next;
    LNode *temp; //用于临时存储后继结点
    while (p1 != NULL && p2 != NULL) {
        //用头插法将较小的结点插入A
        if (p1->data < p2->data) {
            temp = p1->next;
            p1->next = A->next;
            A->next = p1;
            p1 = temp;
        }
        else {
            temp = p2->next;
            p2->next = A->next;
            A->next = p2;
            p2 = temp;
        }
    }

    if (p1 != NULL) //结束上面操作之后，一般来说，A和B会剩下一个链表不为空
        p2 = p1;

    while (p2 != NULL) {
        temp = p2->next;
        p2->next = A->next;
        A->next = p2;
        p2 = temp;
    }
    free(B);
    return A;

    free(B);
    return A;
}

//合成顺序表
LinkList MergeList_L(LinkList &A, LinkList &B) {
    LNode *pa = A->next;
    LNode *pb = B->next;
    LNode *pc = A;

    // pa、pb均不指向NULL,La和Lb中均不为空
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pc->next;
        }
        // pa较小，将pa当前指向的结点接接到Lc上，pc指向当前节点，pa指向下一个结点
        else {
            pc->next = pb;
            pc = pb;
            pb = pc->next;
        }
        // pb较小，将pb当前指向的结点接接到Lc上，pc指向当前节点，pb指向下一个结点
    }
    pc->next = pa ? pa : pb; //插入剩余段
    /*
    if (pa) pc->next = pa;
    else pc->next = pb;
    */
    free(B);
    return A;
}

// 将带表头节点的单链表逆置
Status ListOppose(LinkList &L) {
    LinkList q, p, s;
    p = L;
    p = p->next;
    L->next = NULL;
    while (p) {
        q = p;
        p = p->next;
        q->next = L->next;
        L->next = q;
    }
    return OK;
}
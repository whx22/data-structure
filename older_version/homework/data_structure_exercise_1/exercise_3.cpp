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
    printf("�������뿪ʼʱ��������ĵ�����A���ж��ٸ�Ԫ�أ�");
    while (scanf("%d", &m) != 1) {
        while (ch = getchar() != '\n') {
            putchar(ch);
            printf("���ǺϷ����롣\n���ٴ����룺");
        }
    }
    LinkList A;
    InitLinkList(A);
    CreatListTail(A, m);

    printf("�������뿪ʼʱ��������ĵ�����B���ж��ٸ�Ԫ�أ�");
    while (scanf("%d", &n) != 1) {
        while (ch = getchar() != '\n') {
            putchar(ch);
            printf("���ǺϷ����롣\n���ٴ����룺");
        }
    }

    LinkList(B);
    InitLinkList(B);
    CreatListTail(B, n);

    printf("��������ĵ�����A�е�Ԫ������Ϊ����  ");
    if (A->next != NULL) {
        LNode *print = A->next;
        while (print != NULL) {
            printf("%d  ", print->data);
            print = print->next;
        }
    }
    printf("��\n");

    printf("��������ĵ�����B�е�Ԫ������Ϊ����  ");
    if (B->next != NULL) {
        LNode *print = B->next;
        while (print != NULL) {
            printf("%d  ", print->data);
            print = print->next;
        }
    }
    printf("��\n");

    // A = MergeList_L(A, B);
    // ListOppose(A);
    A = MergeLinkList(A, B);

    printf("A��B��ϲ����γɵĵݼ�����ĵ�����C�е�Ԫ������Ϊ����  ");
    if (A->next != NULL) {
        LNode *print = A->next;
        while (print != NULL) {
            printf("%d  ", print->data);
            print = print->next;
        }
    }
    printf("��\n");

    return 0;
}

//��ͷ���ĵ������ʼ��
Status InitLinkList(LinkList &L) {
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    return OK;
}

//β�巨������ͷ���ĵ�����������L�Ѵ��ڣ�
void CreatListTail(LinkList &L, int n) {
    srand(time(NULL));
    int num = 0;
    LNode *r = L; // r��ָ��β��㣨rΪβָ�룩
    for (int i = 0; i < n; i++) {
        LNode *p = (LNode *)malloc(sizeof(LNode));
        num += rand() % 20 + 1;
        p->data = num;
        r->next = p;
        r = p;
    }
    r->next = NULL; //����������β����ָ����ָ��NULL
}

//ͷ�巨���β�����Сֵ
LinkList MergeLinkList(LinkList &A, LinkList &B) {
    LNode *p1 = A->next;
    A->next = NULL; //ѡ��A��Ϊ��������ͷָ�룬�Ƚ���������ʼ��Ϊ��
    LNode *p2 = B->next;
    LNode *temp; //������ʱ�洢��̽��
    while (p1 != NULL && p2 != NULL) {
        //��ͷ�巨����С�Ľ�����A
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

    if (p1 != NULL) //�����������֮��һ����˵��A��B��ʣ��һ������Ϊ��
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

//�ϳ�˳���
LinkList MergeList_L(LinkList &A, LinkList &B) {
    LNode *pa = A->next;
    LNode *pb = B->next;
    LNode *pc = A;

    // pa��pb����ָ��NULL,La��Lb�о���Ϊ��
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pc->next;
        }
        // pa��С����pa��ǰָ��Ľ��ӽӵ�Lc�ϣ�pcָ��ǰ�ڵ㣬paָ����һ�����
        else {
            pc->next = pb;
            pc = pb;
            pb = pc->next;
        }
        // pb��С����pb��ǰָ��Ľ��ӽӵ�Lc�ϣ�pcָ��ǰ�ڵ㣬pbָ����һ�����
    }
    pc->next = pa ? pa : pb; //����ʣ���
    /*
    if (pa) pc->next = pa;
    else pc->next = pb;
    */
    free(B);
    return A;
}

// ������ͷ�ڵ�ĵ���������
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
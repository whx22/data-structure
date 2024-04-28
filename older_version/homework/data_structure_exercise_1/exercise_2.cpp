#include "base.h"

Status ListDelete(SeqList &L, int i, int k, SeqList &DL);

int main(void) {
    SeqList L, DL;
    InitSeqList(L);
    InitSeqList(DL);

    int n;
    char ch;
    printf("请您输入开始时数组中有多少个元素：");
    while (scanf("%d", &n) != 1) {
        while (ch = getchar() != '\n') {
            putchar(ch);
            printf("不是合法输入。\n请再次输入：");
        }
    }

    srand(time(NULL));
    int temp = 0;
    for (int i = 0; i < n; i++) {
        temp = rand() % 100 + 1;
        ListInsert(L, i + 1, temp);
    }
    
    printf("删除前表中数值分别为：（   ");
    for (int i = 0; i < L.length; i++) {
        printf("%d  ", L.data[i]);
    }
    printf("）\n");
    
    int i, k;
    printf("请输入您要从第几个数字开始删除（1~%d）：", L.length);
    while (scanf("%d", &i) != 1) {
        while (ch = getchar() != '\n') {
            putchar(ch);
            printf("不是合法输入。\n请再次输入：");
        }
    }
    printf("请输入您要删除几个数字（0~%d）：", L.length - i + 1);
    while (scanf("%d", &k) != 1) {
        while (ch = getchar() != '\n') {
            putchar(ch);
            printf("不是合法输入。\n请再次输入：");
        }
    }

    ListDelete(L, i, k, DL);

    printf("删除后表中数值分别为：（   ");
    for (int i = 0; i < L.length; i++) {
        printf("%d  ", L.data[i]);
    }
    printf("）\n");

    printf("删除的数值分别是：（   ");
    for (int i = 0; i < DL.length; i++) {
        printf("%d  ", DL.data[i]);
    }
    printf("）\n");

    return 0;
}

Status ListDelete(SeqList &L, int i, int k, SeqList &DL) {
    if (L.length < k || i < 1 || i + k > L.length + 1)
        return ERROR;
    int court = 0;
    for (int j = i; j < i + k; j++) {
        DL.data[court] = L.data[j - 1];
        court++;
    }
    if (i + k < L.length + 1) {
        for (int l = i + k - 1; l <= L.length - 1; l++) {
            L.data[l - k] = L.data[l];
        }
    }
    L.length -= k;
    DL.length += k;
    return OK;
}
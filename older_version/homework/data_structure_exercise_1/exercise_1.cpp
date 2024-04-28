//对顺序表元素赋连续递增初值
#include "base.h"

Status SeqListInsert(SeqList &L, ElemType e);

int main(void) {
    SeqList L;
    InitSeqList(L);

    int n;
    char ch;
    printf("请您输入开始时数组中有多少个元素：");
    while (scanf("%d", &n) != 1) {
        while (ch = getchar() != '\n') {
            putchar(ch);
            printf("不是合法输入。\n请再次输入：");
        }
    }

    //对顺序表中元素赋连续递增初值
    srand(time(NULL));
    int temp = 0;
    for (int i = 0; i < n; i++) {
        temp += rand() % 20 + 1;
        ListInsert(L, i + 1, temp);
    }

    printf("插入前表中数值分别为：（   ");
    for (int i = 0; i < L.length; i++) {
        printf("%d  ", L.data[i]);
    }
    printf("）\n");
    int k;
    printf("请输入需要插入的数字：");
    scanf("%d", &k);
    SeqListInsert(L, k);
    printf("插入后表中数值分别为：（   ");
    for (int i = 0; i < L.length; i++) {
        printf("%d  ", L.data[i]);
    }
    printf("）\n");
    return 0;
}

Status SeqListInsert(SeqList &L, ElemType e) {
    if (L.length == MAXSIZE)
        return ERROR;
    int i = 1; // e插入顺序表的第i位
    while (e >= L.data[i - 1]) {
        i++;
    }
    if (i <= L.length) {
        for (int j = L.length - 1; j >= i - 1; j--) {
            L.data[j + 1] = L.data[j];
        }
    }
    L.data[i - 1] = e;
    L.length++;
    return OK;
}
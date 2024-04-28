//��˳���Ԫ�ظ�����������ֵ
#include "base.h"

Status SeqListInsert(SeqList &L, ElemType e);

int main(void) {
    SeqList L;
    InitSeqList(L);

    int n;
    char ch;
    printf("�������뿪ʼʱ�������ж��ٸ�Ԫ�أ�");
    while (scanf("%d", &n) != 1) {
        while (ch = getchar() != '\n') {
            putchar(ch);
            printf("���ǺϷ����롣\n���ٴ����룺");
        }
    }

    //��˳�����Ԫ�ظ�����������ֵ
    srand(time(NULL));
    int temp = 0;
    for (int i = 0; i < n; i++) {
        temp += rand() % 20 + 1;
        ListInsert(L, i + 1, temp);
    }

    printf("����ǰ������ֵ�ֱ�Ϊ����   ");
    for (int i = 0; i < L.length; i++) {
        printf("%d  ", L.data[i]);
    }
    printf("��\n");
    int k;
    printf("��������Ҫ��������֣�");
    scanf("%d", &k);
    SeqListInsert(L, k);
    printf("����������ֵ�ֱ�Ϊ����   ");
    for (int i = 0; i < L.length; i++) {
        printf("%d  ", L.data[i]);
    }
    printf("��\n");
    return 0;
}

Status SeqListInsert(SeqList &L, ElemType e) {
    if (L.length == MAXSIZE)
        return ERROR;
    int i = 1; // e����˳���ĵ�iλ
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
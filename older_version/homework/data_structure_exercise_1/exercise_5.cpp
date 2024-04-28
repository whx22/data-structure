#include "base.h"

typedef struct {
    char ch[MAXSIZE];
    int len;
} SeqString;

// ��ʼ���ַ���
Status InitString(SeqString &S) {
    S.len = 0;
    return OK;
}

// ��ӡ�ַ�����
void Print(SeqString S) {
    if (S.len == 0) {
        printf("��Ϊ:��\n");
        return;
    }
    printf("��Ϊ:");
    int i = 0;
    for (i = 0; i < S.len; i++) {
        printf("%c", S.ch[i]);
    }
    printf("\n");
}

// �滻�ַ�����
Status Replace(SeqString &s1, SeqString s2, int i, int j) {
    if (i > s1.len || j > s1.len || i > j) {
        printf("��������滻λ�ò�����\n");
        return ERROR;
    }
    if (j - i + 1 > s2.len) {
        for (int t = 0, k = 0; t < s2.len; t++, k++) {
            s1.ch[t + i] = s2.ch[k];
        }
    }
    else {
        for (int t = i, k = 0; t <= j; t++, k++) {
            s1.ch[t] = s2.ch[k];
        }
    }
    return OK;
}

int main() {
    SeqString s1;
    InitString(s1);
    printf("��������--��s1��");
    scanf("%s", s1.ch);
    s1.len = strlen(s1.ch);

    SeqString s2;
    InitString(s2);
    printf("��������--��s2��");
    scanf("%s", s2.ch);
    s2.len = strlen(s2.ch);
    printf("�����滻ǰ��\n");
    printf("s1");
    Print(s1);
    printf("s2");
    Print(s2);

    printf("��ʼ�����滻...\n");
    printf("������s2���ȴ����滻λ��ʱ����s2ǰ�滻λ�����ַ��滻��\n");
    printf("��������--��ʼ�滻���ַ�λ��:");
    int i;
    scanf("%d", &i);
    printf("��������--�����滻���ַ�λ��:");
    int j;
    scanf("%d", &j);

    Replace(s1, s2, i - 1, j - 1);
    printf("�滻��s1");
    Print(s1);
    return 0;
}
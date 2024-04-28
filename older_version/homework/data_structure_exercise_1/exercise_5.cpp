#include "base.h"

typedef struct {
    char ch[MAXSIZE];
    int len;
} SeqString;

// 初始化字符串
Status InitString(SeqString &S) {
    S.len = 0;
    return OK;
}

// 打印字符函数
void Print(SeqString S) {
    if (S.len == 0) {
        printf("串为:空\n");
        return;
    }
    printf("串为:");
    int i = 0;
    for (i = 0; i < S.len; i++) {
        printf("%c", S.ch[i]);
    }
    printf("\n");
}

// 替换字符函数
Status Replace(SeqString &s1, SeqString s2, int i, int j) {
    if (i > s1.len || j > s1.len || i > j) {
        printf("您输入的替换位置不合理！\n");
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
    printf("请您输入--串s1：");
    scanf("%s", s1.ch);
    s1.len = strlen(s1.ch);

    SeqString s2;
    InitString(s2);
    printf("请您输入--串s2：");
    scanf("%s", s2.ch);
    s2.len = strlen(s2.ch);
    printf("进行替换前：\n");
    printf("s1");
    Print(s1);
    printf("s2");
    Print(s2);

    printf("开始进行替换...\n");
    printf("（规则：s2长度大于替换位数时仅用s2前替换位数的字符替换）\n");
    printf("请您输入--开始替换的字符位置:");
    int i;
    scanf("%d", &i);
    printf("请您输入--结束替换的字符位置:");
    int j;
    scanf("%d", &j);

    Replace(s1, s2, i - 1, j - 1);
    printf("替换后s1");
    Print(s1);
    return 0;
}
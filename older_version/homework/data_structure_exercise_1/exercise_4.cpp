#include "base.h"

int main() {
    SeqStack S;
    InitStack(S);
    SeqQueue Q;
    InitQueue(Q);

    int flag = 1;
    printf("请输入一串字符（最多不超过100个字符）：");
    char ch1, ch2;
    while ((ch1 = getchar()) != '&') {
        Push(S, ch1);
    }
    while ((ch2 = getchar()) != '@') {
        EnQueue(Q, ch2);
    }

    char ch3, ch4;
    if (QueueLength(Q) != StackLength(S))
        flag = 0;
    else {
        int num = QueueLength(Q);
        for (int i = 0; i < num; i++) {
            Pop(S, ch3);
            DeQueue(Q, ch4);
            if (ch3 == ch4) {
                flag = 1;
            }
            else {
                flag = 0;
                break;
            }
        }
    }

    if (flag) {
        printf("该字符串是回文字符串！");
    }
    else {
        printf("该字符串不是回文字符串！");
    }
    return 0;
}
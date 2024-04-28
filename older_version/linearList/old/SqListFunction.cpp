#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

#define MAXSIZE 100

typedef char ElemType;
typedef struct SeqList {
    ElemType data[MAXSIZE];
    int length;
} SqList;

// 注意：1.顺序表中存储结构=逻辑结构-1
// 表长、位置均为逻辑结构，对数组元素操作时为存储结构

// 1.顺序表的获取元素，获取第i位元素，通过e返回
// （随机存储结构,时间复杂度：O(1)）
Status GetElem(SqList L, int i, ElemType &e);

// 2.顺序表插入元素，改变表L，将元素e插入到第i位
// （需要移动(length-i+1)个元素,时间复杂度：O(n)）
Status ListInsert(SeqList &L, int i, ElemType e);

// 3.顺序表删除元素，改变表L，删除第i位元素，并保存其值
// （需要移动(length-i)个元素,时间复杂度：O(n)）
Status ListDelete(SqList &L, int i, ElemType &e);

Status GetElem(SqList L, int i, ElemType &e) {
    if (L.length == 0 || i < 1 || i > L.length) return ERROR;
    e = L.data[i-1];
    return OK;
}

Status ListInsert(SeqList &L, int i, ElemType e) {
    if (L.length == MAXSIZE || i < 1 || i > L.length + 1) return ERROR;
    
    if (i <= L.length) {
        for (int j = L.length - 1; j >= i - 1; j--) {
            L.data[j+1] = L.data[j];
        }
    }
    L.data[i-1] = e;
    L.length++;
    return OK;
}

Status ListDelete(SqList &L, int i, ElemType &e) {
    if (L.length == 0 || i < 1 || i > L.length) { return ERROR; }

    e = L.data[i-1];
    if (i < L.length) {
        for (int j = i; j <= L.length - 1; j++) {
            L.data[j-1] = L.data[j];
        }
    }
    L.length--;
    return OK;
}
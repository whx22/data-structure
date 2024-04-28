// 静态链表（游标实现法）：用数组描述的链表
// 早期没有指针的高级语言（Basic、Fortran等）实现链式结构
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

#define MAXSIZE 1000    // 静态链表大小固定后则不能改变

typedef char ElemType;
typedef struct {       
    ElemType data;  
    int cur;    // 游标（Cursor）,为0时表示无指向
} Component, StaticLinkList[MAXSIZE];


// 注意：
//  1.未被使用的数组元素称为备用链表
//  2.第一个元素的cur恒为第一个备用链表元素的下标
//  3.不一定等于存储结构中最后元素的cur，最后元素的cur恒等于"0"（NULL，无指向）
//  4.最后一个元素的cur恒为逻辑存储结构的第一个元素的下标
// 最后一个元素的cur存放第一个插入元素的下标
// （第一个数组元素相当于尾结点）（最后一个数组元素相当于头节点）



// 1.将一维数组space中各分量链成一备用链表
// space[0].cur为头指针，"0"表示空指针
Status InitList(StaticLinkList space);

// 2.静态链表的插入,需要实现动态分配空间的功能（类似malloc()和free()函数的功能）
// 输入一个静态链表，返回该链表的可用数组下标，并且第一个元素的cur指向下一个备用数组元素
int Malloc_SLL(StaticLinkList space);

// 3.在L中第i个元素之前插入新的数据元素e
// 不移动元素，将新数据e插入到当前的第一的备用节点
// 仅通过修改下标的方法实现，逻辑结构上第i位的插入
Status ListInsert(StaticLinkList L, int i, ElemType e);

// 4.输入静态链表，输出其中元素的个数
int ListLength(StaticLinkList L);

// 5.静态链表的删除元素操作，需要用到释放节点的函数（类似free()函数）
// 释放该节点，并将该节点改为备用链表的第一个元素
// 并将原备用链表的第一个元素的下标存储到该节点的cur
void Free_SLL(StaticLinkList space, int i);

// 6.静态链表的删除元素操作
Status ListDelete(StaticLinkList L, int i);

Status InitList(StaticLinkList space) {
    // 第一个元素的cur存放第一个备用链表,空表时，存放首元节点的下表
    // 其他备用链表的节点cur均为下一位数组元素下标
    for (int i = 0; i < MAXSIZE - 1; i++) {
        space[i].cur = i + 1;
    }
    space[MAXSIZE - 1].cur = 0; 
    // 最后一个元素的cur存放第一个插入元素的下标（相当于头节点）
    // 此时为空表，"0"表示空指针
    return OK;
}

int Malloc_SLL(StaticLinkList space) {
    int i = space[0].cur;
    // 当前第一个备用节点的下标
    if (space[0].cur) { space[0].cur = space[i].cur; }
    // 判断条件第一个元素的cur指向不为"0"（指向NULL，数组已满）
    // 第一个元素的cur指向当前位置下一个位
    return i;
}

Status ListInsert(StaticLinkList L, int i, ElemType e) {
    if (i < 1 || i > ListLength(L) + 1) return ERROR;   // 插入位置非法
    
    // 获取第一个备用节点的下标
    int j = Malloc_SLL(L);  
    // k为最后一个元素的下标，cur存储首元节点的下标
    int k = MAXSIZE - 1;        

    if(j) { // 静态链表未满
        L[j].data = e;  // 对该位置赋值
        // 遍历k找到插入位置i的前一位（等同于链表中头指针遍历到i-1的位置）
        // 循环结束时k == L[i - 1].cur == i;         
        for (int l; l <= i - 1; l++) {
            k = L[l].cur;
        }
        L[j].cur = L[k].cur;    
        // 将新插入的结点cur改为i的下一位
        // （等同于链表中将插入结点的指针域赋值为更改后逻辑第i+1位）
        
        L[k].cur = j;           
        // 将新插入的节点位置赋值给i-1位的cur
        // （等同于链表中将插入节点的address赋值给逻辑i-1位）
        return OK;
    }  
    else return ERROR;
}

int ListLength(StaticLinkList L) {
    int court;
    int i = L[MAXSIZE - 1].cur;
    
    // 从第一个数据元素开始，遍历所有数据元素
    while (i) {
        i = L[i].cur;
        court ++;
    }

    return court;
}

void Free_SLL(StaticLinkList space, int i) {
    space[i].cur = space[0].cur;
    space[0].cur = i;
}

Status ListDelete(StaticLinkList L, int i) {
    if (i < 1 || i > ListLength(L)) { return ERROR; }
    // k为最后一个元素的下标，cur存储首元节点的下标
    int k = MAXSIZE - 1;
    // 遍历k找到插入位置i的前一位（等同于链表中头指针遍历到i-1的位置）
    // 循环结束时k == L[i - 1].cur == i; 
    for (int l; l <= i - 1; l++) {
        k = L[l].cur;
    }
    // 定义一个temp存放需要释放的位置i的下标
    int temp = L[k].cur;
    // 将k（i-1）的cur存入i+1位置元素的下标
    L[k].cur = L[temp].cur;
    // 释放该结点
    Free_SLL(L, temp);
    return OK;
}
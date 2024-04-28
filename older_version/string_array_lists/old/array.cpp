#include <stdio.h>
#include <stdlib.h>

typedef int elemType;
// 二维数组的定义
int m = 10, n = 10;
typedef elemType array2[5][8];  // 5行，8列
// 等价于
typedef elemType array1[8]; // 一行8列
typedef array1 array2[5];   // 共5行 

// 数组的基本操作
// 构造数组（维数n，第i维边界数boundi）
// InitArray(array2 &A,int n,int  bound1, ..., int boundn);

// 销毁数组A
// DestroyArray(array2 &A);

// 取数组元素值
// Value(array2 A,elemType &e,int index1, ...,int indexn);

// 给数组元素赋值
// Assign(array2 &A,elemType e,int index1, ..., int indexn);	
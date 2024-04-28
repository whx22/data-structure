// 递归--分治法（两步：递推+回归）
// 分治法：将复杂大的问题，分解为多个解法相同或类似的简单问题求解
// 使用条件：
//  1.原问题可以分为多个简单问题
//  （解法相同或类似，处理对象不同，处理对象的变化有规律）
//  2.通过转化可以简化问题
//  3.必须有明确的递归出口（或称递归边界）

/*
void p(参数表) {
    if (递归结束条件) return 可直接求解步骤;       // 基本项
    else p(较小的参数);                         // 归纳项   
}
*/

// 递归算法的应用
// 1.递归定义的数学函数
//  a.阶乘函数
//  b.Fibonacci函数（斐波那契数列）：1、2项为1，其余项为前两项的和
// 2.数据结构本身具有的递归特性
//  a.二叉树root的Lchild和Rchild具有相同的数据结构
//  b.广义表中的元素也可以是广义表
// 3.递归解决问题
//  a.迷宫问题
//  b.Hanoi塔

#include <stdio.h>

long int Fact(int n) {
    if (n == 0) { return 1; }
    else { return (n * Fact(n - 1)); }
}

int main(void) {
    int i, result;
    printf("Please input a integer:");
    scanf("%d", &i);
    result = Fact(i);
    printf("The result is %d", result);
    return 0;
}
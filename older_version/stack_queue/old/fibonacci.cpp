#include <stdio.h>
#include <stdlib.h>

int Fibonacci(int i);

int main(void) {
    int fibonacci[40];
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    // 循环实现fibonacci数列
    for (int i = 2; i < 40; i++) {
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
        printf("fibonacci[%d] = %d\n", i, fibonacci[i]);//
    }   
    
    // 递归实现Fibonacci数列
    for (int i = 0; i < 40; i++) {
        printf("fibonacci[%d] = %d\n", i, Fibonacci(i));
    }
    return 0;
}

// 递归实现Fibonacci数列
int Fibonacci(int i) {
    if (i < 2) return i ? 1 : 0;
    return Fibonacci(i - 1) + Fibonacci(i - 2);
}
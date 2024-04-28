/*
任意输入一个不超过20的正整数
1.判断其是否是素数
2.求平方
3.求阶乘

请注意以下几点：
1)编程的规范性：程序、变量及函数的命名要词能达意、按需缩进、添加必要的注释；（20分）
2)结构的合理性：必要的功能封装（要求将每个运算封装为一个函数或方法，注意函数调用、参数传递，采用不同算法实现相同功能的应分开封装）；（20分）
3)程序的正确性：对输入的合理数据，运算结果要准确无误；（30分）
4)操作的友好性：对输入、输出或异常都应该有适当的文字提示；（10分）
5)算法分析：分析所采用的每个算法的时间复杂度（采用不同算法实现相同功能的，建议输出运行时间差）。（20分）


问题：
1.再次测试、循环结束条件
2.小数的判别
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXK 1e7    //被测函数重复次数

clock_t start, stop;
double duration;//存放被测函数运行时间，单位为秒

int isPrime_1(int);             // 判断素数函数
int square_1(int);              // 求平方函数
long long int factorial_1(int); // 求阶乘函数1（循环）
long long int factorial_2(int); // 求阶乘函数2（递归）

int isPrime_1(int num)// 判断素数函数
{
    int ret = 1;

    if (num == 1 || num % 2 == 0 && num != 2)
    {
        ret = 0;
    }
    for (int i = 3; i < num; i += 2)
    {
        if (num % i == 0)
        {
            ret = 0;
            break;
        }
    }

    return ret;
}

int square_1(int num)// 求平方函数
{
    int square = num * num;

    return square;
}

long long int factorial_1(int num)// 求阶乘函数1（循环）
{
    long long int factorial = 1;
    for (int i = num; i >= 1; i--)
    {
        factorial *= i;
    }

    return factorial;
}

long long int factorial_2(int num)//求阶乘函数2（递归）
{

    if (num <= 1)
    {
        return 1;
    }
    else
    {
        return (num * factorial_2(num - 1));
    }
}



int main(void)// 主函数
{
    int num;
    long long int factorial;

    printf("请输入一个不超过20的正整数：");
    scanf_s("%d", &num);
    if (num < 1 || num > 21)                      // 输入判别
    {
        printf("您的输入异常！！！\n");
        exit(1);
    }

    if (isPrime_1(num))                           // 判断素数
    {
        printf("%d是素数！\n", num);
    }
    else
    {
        printf("%d不是素数！\n", num);
    }

    printf("%d的平方是：%d\n", num, square_1(num));// 求平方

    start = clock();                              
    for (int i = 0; i < MAXK; i++)
    {
        factorial = factorial_1(num);             // 循环求阶乘
    }
    stop = clock();
    duration = ((double)(stop - start)) / CLK_TCK / MAXK;
    printf("%d的阶乘是：%lld\t（循环方法用时：%le秒）\n", num, factorial, duration);

    start = clock();
    for (int i = 0; i < MAXK; i++)
    {
        factorial = factorial_2(num);             // 递归求阶乘
    }
    stop = clock();
    duration = ((double)(stop - start)) / CLK_TCK / MAXK;
    printf("%d的阶乘是：%lld\t（递归方法用时：%le秒）\n", num, factorial, duration);

    return 0;
}
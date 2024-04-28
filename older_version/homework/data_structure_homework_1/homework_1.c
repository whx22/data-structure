/*
��������һ��������20��������
1.�ж����Ƿ�������
2.��ƽ��
3.��׳�

��ע�����¼��㣺
1)��̵Ĺ淶�ԣ����򡢱���������������Ҫ���ܴ��⡢������������ӱ�Ҫ��ע�ͣ���20�֣�
2)�ṹ�ĺ����ԣ���Ҫ�Ĺ��ܷ�װ��Ҫ��ÿ�������װΪһ�������򷽷���ע�⺯�����á��������ݣ����ò�ͬ�㷨ʵ����ͬ���ܵ�Ӧ�ֿ���װ������20�֣�
3)�������ȷ�ԣ�������ĺ������ݣ�������Ҫ׼ȷ���󣻣�30�֣�
4)�������Ѻ��ԣ������롢������쳣��Ӧ�����ʵ���������ʾ����10�֣�
5)�㷨���������������õ�ÿ���㷨��ʱ�临�Ӷȣ����ò�ͬ�㷨ʵ����ͬ���ܵģ������������ʱ������20�֣�


���⣺
1.�ٴβ��ԡ�ѭ����������
2.С�����б�
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXK 1e7    //���⺯���ظ�����

clock_t start, stop;
double duration;//��ű��⺯������ʱ�䣬��λΪ��

int isPrime_1(int);             // �ж���������
int square_1(int);              // ��ƽ������
long long int factorial_1(int); // ��׳˺���1��ѭ����
long long int factorial_2(int); // ��׳˺���2���ݹ飩

int isPrime_1(int num)// �ж���������
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

int square_1(int num)// ��ƽ������
{
    int square = num * num;

    return square;
}

long long int factorial_1(int num)// ��׳˺���1��ѭ����
{
    long long int factorial = 1;
    for (int i = num; i >= 1; i--)
    {
        factorial *= i;
    }

    return factorial;
}

long long int factorial_2(int num)//��׳˺���2���ݹ飩
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



int main(void)// ������
{
    int num;
    long long int factorial;

    printf("������һ��������20����������");
    scanf_s("%d", &num);
    if (num < 1 || num > 21)                      // �����б�
    {
        printf("���������쳣������\n");
        exit(1);
    }

    if (isPrime_1(num))                           // �ж�����
    {
        printf("%d��������\n", num);
    }
    else
    {
        printf("%d����������\n", num);
    }

    printf("%d��ƽ���ǣ�%d\n", num, square_1(num));// ��ƽ��

    start = clock();                              
    for (int i = 0; i < MAXK; i++)
    {
        factorial = factorial_1(num);             // ѭ����׳�
    }
    stop = clock();
    duration = ((double)(stop - start)) / CLK_TCK / MAXK;
    printf("%d�Ľ׳��ǣ�%lld\t��ѭ��������ʱ��%le�룩\n", num, factorial, duration);

    start = clock();
    for (int i = 0; i < MAXK; i++)
    {
        factorial = factorial_2(num);             // �ݹ���׳�
    }
    stop = clock();
    duration = ((double)(stop - start)) / CLK_TCK / MAXK;
    printf("%d�Ľ׳��ǣ�%lld\t���ݹ鷽����ʱ��%le�룩\n", num, factorial, duration);

    return 0;
}
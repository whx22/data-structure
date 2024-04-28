//插入排序

#include "head.h"


//1.直接插入排序算法
void InsertSort(SeqList &L)
{
    //i为当前正在插入的元素的下标，j为游标（寻找插入位置的下标）
    int i, j;

    //从第2~n个元素，依次插入有序表
    for (i = 2; i <= L.length; i++) 
    {
        //当前i的值大于有序表的最大值，无需已插入
        //若i值小于有序表的最大值，需将i的值插入有序表
        if (L.list[i].key < L.list[i - 1].key)
        {
            L.list[0] = L.list[i];  //0位置为哨兵
            
            //寻找插入位置
            for (j = i - 1; L.list[j].key < L.list[i].key; j--)
            {
                L.list[j + 1] = L.list[j];  //大于当前i值，向后移动  
            }
            L.list[j + 1].key = L.list[0].key;  //将i的值插入j+1的位置
        }
    }
}


//2.二分插入排序算法
void BinaryInsertSort(SeqList &L)
{
    //从第2~n个元素，依次插入有序表，i为当前正在插入的元素的下标
    for (int i = 2; i < L.length; i++)
    {
        L.list[0] = L.list[i];  //0位置为哨兵

        //采用二分查找法查找插入位置
        int low = 1, high = i - 1;
        while (low <= high)
        {
            int mid = (int) ((low + high) / 2);
            if (L.list[0].key < L.list[mid].key) high = mid - 1;
            else low = mid + 1;  
        }   //循环结束时，high+1为插入位置

        //将第(i-1)~(high+1)向后移一位
        for (int j = i - 1; j >= high + 1; j--)
        {
            L.list[j + 1] = L.list[j];
        }

        //插入到正确位置
        L.list[high + 1] = L.list[0];
    }
}


//3.希尔排序

//希尔排序（主程序）
//gaps数组中按降序存放t个（ShellInsert函数中参数步长因子gap）
//gaps数组中元素特点：为递减的互质数，最后一个元素为1（即gaps[t-1] = 1）
void ShellSort(SeqList &L, int gaps[], int t)
{
    //进行t次ShellInsert函数，每次步长因子gap为gaps数组中的t-1下标值
    for (int k = 0; k < t; k++)
    {
        ShellInsert(L, gaps[k]);
    }
}

//希尔排序（其中某一趟的排序操作）
//对顺序标L进行一趟增量为gap的shell_sort,gap为步长因子
void ShellInsert(SeqList &L, int gap)
{
    //进行一趟步长为gap的插入排序
    int i, j;
    for (i = 1 + gap; i <= L.length; i++)
    {
        if (L.list[i].key < L.list[i - gap].key)
        {
            L.list[0] = L.list[i];
            for (j = i - gap; (j > 0) && (L.list[0].key < L.list[j].key); j = j-gap)
            {
                L.list[j + gap] = L.list[j];
            }
            L.list[j + gap] = L.list[0];
        }
    }
}
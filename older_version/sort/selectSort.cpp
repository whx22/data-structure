//选择排序

#include "head.h"


//简单选择排序
void SimpleSelectSort(SeqList &L)
{
    //从L.list[1]开始，选择(L.length - 1)次，则排序完成
    for (int i = 1; i < L.length; i++)
    {
        int min = i;    //设置当前key值最小元素下标为第i位置

        //从第(i+1)~(L.length)位元素中查找比当前min小的值
        for (int j = i + 1; j <= L.length; j++)
        {
            //若查找到了key值比第min位更小的位置
            if (L.list[j].key < L.list[min].key)
            {
                min = j;    //记录最小值位置
            }
        }
        
        //若当前轮key值最小位值不是第i位，这将最小key值的结点交换到第i位的元素位置
        if (min != i)
        {
            RecordType temp;
            temp = L.list[i];
            L.list[i] = L.list[min];
            L.list[min] = temp;
        }
    }
}


//堆排序

//堆排序排序元素类型的定义
typedef int heap_elem;
heap_elem H[MAXSIZE];

//筛选过程的算法
/*
已知H[s...m]中记录的关键字除H[s]外均满足堆的定义
本函数调整H[s]的关键字（）
使H[s...m]成为一个大根堆
*/
void HeapAdjust(heap_elem H[], int s, int m)
{
    heap_elem temp = H[s];

    //沿关键字较大的孩子结点向下筛选
    for (int j = 2 * s; j <= m; j *= 2)
    {
        //选出左、右孩子中关键字较大的记录至下标j中
        if (j < m && H[j] < H[j + 1]) {j++;}

        //找到H[s]应插入的位置（即此时H[s]）退出循环
        if (temp >= H[j]) {break;}

        //每一次循环，将于左、右孩子中关键字较大的结点作为当前树的根结点
        H[s] = H[j];
        s = j;
    }

    H[s] = temp;    //插入H[s]，堆的筛选完成
}

//堆的建立算法
/*
对已知H[1...n]中记录的关键字进行堆的建立（大根堆）
length = n（最后一个元素的下标）为H[]中元素个数，H[0]不存储元素
*/
void HeapCreate(heap_elem H[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        HeapAdjust(H, i, n);
    }
}

//推排序算法
//对H[1]~H[n]进行堆排序（大根堆）
//length = n（最后一个元素的下标）为H[]中元素个数，H[0]不存储元素
void HeapSort(heap_elem H[], int length)    
{
    //建立初始堆
    int n = length;
    for (int i = n / 2; i >= 1; i--)
    {
        HeapAdjust(H, i, n);
    }

    //进行n-1趟排序
    for (int i = n; i > 1; i--)
    {
        //根（当前堆（大根堆）中最大的元素）与最后一个元素交换
        Swap(H[1], H[i]); 

        //对H[1]~H[i - 1]重新建立堆
        HeapAdjust(H, 1, i - 1);
    }
}

//交换位置函数
void Swap(heap_elem root, heap_elem last)
{
    heap_elem temp;
    temp = last;
    last = root;
    root = temp;
}
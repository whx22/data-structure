//交换排序

#include "head.h"


//1.1冒泡排序算法
void BubblingSort1(SeqList &L)
{
    RecordType temp;    //交换时用到的临时变量temp
    
    int n = L.length;  //总共有n个元素需要排序,为传入SeqList的元素个数
    //总共需要m躺（有n个元素，则m = n - 1）
    for (int m = 1; m <= n - 1; m++)
    {
        //每一趟需要比较n-m次，每一次从L.list[1]开始比较，L.list[0]作哨兵或缓冲区
        for (int i = 1; i <= n - m; i++)
        {
            if (L.list[i].key > L.list[i + 1].key)  //发生逆序
            {
                //交换顺序
                temp = L.list[i];
                L.list[i] = L.list[i + 1];
                L.list[i + 1] = temp;
            }
        }
    }
}

//1.2改进的冒泡排序算法
void BubblingSort2(SeqList &L)
{
    RecordType temp;    //交换时用到的临时变量temp
    int flag = 1;   //flag作为是否有交换的标记，发生交换flag == 1，未发生交换flag == 0
    
    int n = L.length;  //总共有n个元素需要排序,为传入SeqList的元素个数
    //总共需要m趟（有n个元素，则m = n - 1）
    //上一轮进行了交换（flag == 1）且进行的趟数没有到达（L.length - 1）趟
    for (int m = 1; (m <= n - 1) && (flag == 1); m++)
    {
        flag = 0;   //进入每一趟时，将flag置为0

        //每一趟需要比较n-m次，每一次从L.list[1]开始比较，L.list[0]作哨兵或缓冲区
        for (int i = 1; i <= n - m; i++)
        {
            if (L.list[i].key > L.list[i + 1].key)  //发生逆序
            {
                flag = 1;   //发生逆序，需要进行交换，将flag置为1

                //交换顺序
                temp = L.list[i];
                L.list[i] = L.list[i + 1];
                L.list[i + 1] = temp;
            }
        }
    }
}


//快速排序算法（主程序）
//在主函数中调用方法
//QuickSort(L, 1, L.length);    
//L：需要进行排序的顺序表
//1：第一个元素下标
//L.length：最后一个元素下标L.length
//L.list[0]用于存储排序过程中的界点
void QuickSort(SeqList &L, int low, int high)
{
    int pivot;  //中心点

    //表长大于1，则需要寻找中心点
    if (low < high)
    {
        //当前表中下标第[low]~[pivot-1]位元素的key值均小于第pivot位的key值
        //当前表中下标第[pivot+1]~[high]位元素的key值均小于第pivot位的key值
        //第pivot位则为表L排好顺序的位置
        pivot = Partition(L, low, high);
    }
    //对第[low]~[pivot-1]位元素递归排序
    QuickSort(L, low, pivot - 1);
    //对第[pivot+1]~[high]位元素递归排序
    QuickSort(L, pivot + 1, high);
}

//快速排序算法（每一次找到第pivot位排好顺序的位置）
//返回表L中心点pivot的位置，后续可将表L分为[low]~[pivot-1]和[pivot+1]~[high]的两个子表
int Partition(SeqList &L, int low, int high)
{
    L.list[0] = L.list[low];    //将当前表L的L.list[low]（即第一个元素）作为中心点
    int pivot_key = L.list[low].key;    //将当前表L的L.list[low].key值作为界点key值

    //此时L.list[low]结点可视为空

    //循环目的：为pivot_key为key值的中心点找到在表中的下标
    while (low < high)  //low < high ，一直交换表中元素
    {
        //先从后向前找到一个key值小于中心点key值
        while (low < high && L.list[high].key >= pivot_key) {high--;}
        //找到后将该节点搬到low下标结点处
        L.list[low] = L.list[high];
        
        //此时L.list[high]结点可视为空

        //后从前向后找到一个key值大于中心点key值
        while (low < high && L.list[low].key <= pivot_key) {low++;};
        //找到后将该节点搬到high下标结点处
        L.list[high] = L.list[low];

        //此时L.list[low]结点可视为空

    }//循环结束时，low == high
    //low下标即为以pivot_key为key值的中心点的在表L中的排好顺序的的下标
    
    //将中心点搬到其第pivot位排好顺序的位置
    L.list[low] = L.list[0];

    return low; //返回排好顺序的位置的下标值
}
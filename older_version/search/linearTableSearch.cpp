#include "head.h"


//查找元素类型定义
typedef struct  
{
    KeyType key;    //关键字域
    //......    //其他域
}ElemType;

//查找顺序表结构类型定义
typedef struct
{
    ElemType *R;    //表基地址
    int length;
}SeqSearchTable;    //Sequential Search Table（顺序查找表）

SeqSearchTable ST;  //定义顺序表ST


//1.1顺序查找1
int Search_seq1(SeqSearchTable ST, KeyType key)
{
    for (int i = ST.length; i >= 1; i--)    //由后向前顺序查找
    {
        if (ST.R[i].key = key) return i;
    }
}

//1.2顺序查找2
int Search_seq2(SeqSearchTable ST, KeyType key)
{
    int i;
    for (i = ST.length; ST.R[i].key != key; i--)
    {
        if (i <= 0) break;
    }

    if (i > 0) return i;
    else return 0; 
}

//1.3顺序查找3
int Search_seq3(SeqSearchTable ST, KeyType key)
{
    int i;
    for (i = ST.length; ST.R[i].key != key && i > 0; i--);  //注意句尾分号
    if (i > 0) return i;
    else return 0;
}

//1.4顺序查找4（增加一个哨兵、监视哨）
//改进：不需要判断是否越界，减少比较次数
//查找元素较多时，平均查找时间可减少几乎一半
int Search_seq4(SeqSearchTable ST, KeyType key)
{
    ST.R[0].key = key;
    int i;
    for (i = ST.length; ST.R[i].key != key; i--);   //注意句尾分号
    return i;
}   


//2.1二分查找（折半查找、对分查找）非递归算法
int Search_binary_Non_Recursion(SeqSearchTable ST, KeyType key)
{
    int low = 1, high = ST.length;  //设置查找区间值
    while (low <= high)
    {
        int mid = (int)((low + high) / 2);
        if (ST.R[mid].key == key) return mid;    //找到key
        else
        {
            if (ST.R[mid].key > key)    //减小查找区间
            {
                high = mid - 1; //如果mid的值大于key，继续在前半区查找
            }
            else
            {
                low = mid + 1;  //如果mid的值小于key，继续在后半去查找
            }
        }
    }
    return 0;   //没有找到，返回0
}

//2.2二分查找（折半查找、对分查找）递归算法
int Search_binary_Recursion(SeqSearchTable ST, KeyType key, int low, int high)
{
    if (low > high) return 0;   //基线条件1：没有找到，返回0
    int mid = (int)((low + high) / 2);

    if (key == ST.R[mid].key) return mid;   //基线条件2：找到key

    else if (key < ST.R[mid].key)   //递归条件1：key小于当前mid的值
    {
        Search_binary_Recursion(ST, key, low, mid - 1); //在前半区查找
    } 
    else //递归条件2：key大于当前mid的值
    {
        Search_binary_Recursion(ST, key, mid + 1, high);//在后半去查找
    }
}


//3.1分块查找

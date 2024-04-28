//��������

#include "head.h"


//1.ֱ�Ӳ��������㷨
void InsertSort(SeqList &L)
{
    //iΪ��ǰ���ڲ����Ԫ�ص��±꣬jΪ�α꣨Ѱ�Ҳ���λ�õ��±꣩
    int i, j;

    //�ӵ�2~n��Ԫ�أ����β��������
    for (i = 2; i <= L.length; i++) 
    {
        //��ǰi��ֵ�������������ֵ�������Ѳ���
        //��iֵС�����������ֵ���轫i��ֵ���������
        if (L.list[i].key < L.list[i - 1].key)
        {
            L.list[0] = L.list[i];  //0λ��Ϊ�ڱ�
            
            //Ѱ�Ҳ���λ��
            for (j = i - 1; L.list[j].key < L.list[i].key; j--)
            {
                L.list[j + 1] = L.list[j];  //���ڵ�ǰiֵ������ƶ�  
            }
            L.list[j + 1].key = L.list[0].key;  //��i��ֵ����j+1��λ��
        }
    }
}


//2.���ֲ��������㷨
void BinaryInsertSort(SeqList &L)
{
    //�ӵ�2~n��Ԫ�أ����β��������iΪ��ǰ���ڲ����Ԫ�ص��±�
    for (int i = 2; i < L.length; i++)
    {
        L.list[0] = L.list[i];  //0λ��Ϊ�ڱ�

        //���ö��ֲ��ҷ����Ҳ���λ��
        int low = 1, high = i - 1;
        while (low <= high)
        {
            int mid = (int) ((low + high) / 2);
            if (L.list[0].key < L.list[mid].key) high = mid - 1;
            else low = mid + 1;  
        }   //ѭ������ʱ��high+1Ϊ����λ��

        //����(i-1)~(high+1)�����һλ
        for (int j = i - 1; j >= high + 1; j--)
        {
            L.list[j + 1] = L.list[j];
        }

        //���뵽��ȷλ��
        L.list[high + 1] = L.list[0];
    }
}


//3.ϣ������

//ϣ������������
//gaps�����а�������t����ShellInsert�����в�����������gap��
//gaps������Ԫ���ص㣺Ϊ�ݼ��Ļ����������һ��Ԫ��Ϊ1����gaps[t-1] = 1��
void ShellSort(SeqList &L, int gaps[], int t)
{
    //����t��ShellInsert������ÿ�β�������gapΪgaps�����е�t-1�±�ֵ
    for (int k = 0; k < t; k++)
    {
        ShellInsert(L, gaps[k]);
    }
}

//ϣ����������ĳһ�˵����������
//��˳���L����һ������Ϊgap��shell_sort,gapΪ��������
void ShellInsert(SeqList &L, int gap)
{
    //����һ�˲���Ϊgap�Ĳ�������
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
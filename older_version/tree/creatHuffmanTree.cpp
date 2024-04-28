// 哈夫曼树的构造算法
// 存储类型：顺序结构

#include <stdio.h>

typedef struct {
    int weight;                 // 结点权值
    int parent, lchild, rchild; // 双亲、左子、右子结点下标
} HTNode, *HuffmanTree;

// 0.在当前的HT[k]（1<=k<=i-1）中
// 选出两个(parent == 0)且(weight最小)的结点并返回其下标
void Select(HuffmanTree HT, int n, int &s1, int &s2) {
    HT[s1].weight = HT[1].weight;
    for (int i = 2; i < n; i++) {
        if (HT[i].parent == 0) {
            HT[s1].weight = HT[i].weight > HT[s1].weight ? HT[i].weight : HT[s1].weight;
        }
    }

    HT[s2].weight = HT[s1].weight;
    for (int i = 2; i < n; i++) {
        if (HT[i].parent == 0) {
            HT[s2].weight = HT[i].weight > HT[s2].weight ? HT[i].weight : HT[s2].weight;
        }
    }
}

// 1.HuffmanTree的建立
void CreatHuffmanTree(HuffmanTree &HT, int n) {
    if (n <= 1)
        return;
    int m = 2 * n - 1;      // 数组总共有2n-1个元素
    HT = new HTNode[m + 1]; // 索引0号元素未用，HT[m]表示根节点

    // 将2n-1个元素的parent，lchild，rchild置为0
    for (int i = 1; i <= m; i++) {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }

    // 依次输入前n个结点（叶节点：度0）的权值
    for (int i = 1; i <= n; i++) {
        scanf("%d", &HT[i].weight);
    }

    // 合并生成n-1个结点（度2）————构造哈夫曼树
    for (int i = n - 1; i <= m; i++) {
        int s1, s2;

        // 在当前的HT[k]（1<=k<=i-1）中
        // 选出两个(parent == 0)且(weight最小)的结点并返回其下标s1，s2
        Select(HT, i - 1, s1, s2);  

        HT[s1].parent = i;  // 修改下标s1的叶节点的双亲结点为i（当前生成结点下标）
        HT[s2].parent = i;  // 修改下标s2的叶节点的双亲结点为i（当前生成结点下标）
        HT[i].lchild = s1;  // s1为i（当前生成结点下标）的左子
        HT[i].rchild = s2;  // s2为i（当前生成结点下标）的右子
        
        // i（当前生成结点下标）的权值为左右子权值之和
        HT[i].weight = HT[s1].weight + HT[s2].weight;   
    }
}
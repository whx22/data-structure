/**
 * @brief 并查集 : Disjoint Set Union(DSU)
 *  1. 并查集是一种树型的数据结构, 用于处理一些不相交集合(Disjoint Sets)的合并及查询问题
 *  2. Disjoint Set Union operation :
 *      1. union 合并操作 : 把两个不相交的集合合并成一个集合
 *      2. find 查询操作 : 查询两个元素是否位于同一个集合
 *      3. count x : x 所在集合的元素个数(使用一个负数存储在集合跟节点的data域中)
 *  3. Disjoin Set Union implementation : 
 *      1. 用数组实现并查集
 *      2. 用链表实现并查集
 */
#include <bits/stdc++.h>
using namespace std;
int N;  // N : the node numbers
int M;  // M : the operator numbers
int dsu[10001];

int Find(int x) {
    if (dsu[x] < 0) {
        return x;
    } else {
        // 优化 : 路径压缩 : 将路径上的所有结点都直接指向根结点
        return dsu[x] = Find(dsu[x]);
    }
}

// union : 把y的集合融入到x集合中 : dsu[x] += dsu[y]; 
void Union(int x, int y) {
    x = Find(x);    // 查找x所在集合的根结点, 用x的根结点覆盖x
    y = Find(y);    // 查找y所在集合的根结点, 用y的根结点覆盖y
    if (x == y) {
        return;
    } else {
        if (dsu[x] < dsu[y]) {      // x集合的元素个数大于y集合的元素个数
            dsu[x] += dsu[y];   // x集合的元素个数增加y集合的元素个数
            dsu[y] = x;         // y集合的根结点指向x集合的根结点
        } else {                    // y集合的元素个数大于x集合的元素个数
            dsu[y] += dsu[x];   // y集合的元素个数增加x集合的元素个数
            dsu[x] = y;         // x集合的根结点指向y集合的根结点
        }
    }
}

int main() {
    memset(dsu, -1, sizeof(dsu));   // initialize dsu data domain to -1
    string operation;   // operation 
    int x, y;           // operation parameter
    cin >> N >> M;
    for (int i = 1; i <= M; ++i) {
        cin >> operation;
        if (operation == "union") {
            cin >> x >> y;
            Union(x, y);
        } else if (operation == "find") {
            cin >> x >> y;
            if (Find(x) == Find(y)) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
        } else if (operation == "count") {
            cin >> x;
            cout << -dsu[Find(x)] << endl;  // 统计x所在集合的元素个数(负数表示)
        }
    }
}
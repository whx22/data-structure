/**
 * @file template_disjoint_set_union.cpp
 * @author whx (huxinwang021@gmail.com)
 * @brief disjoint set union
 * @version 0.1
 * @date 2023-05-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// note : 
//  root node record the number of set element (negative number)
//  other node record its root node index (positive number)

int dsu[10001];

// recursion find the set union's root node
int Find(int x) {
    if (dsu[x] < 0) {
        return x;
    } else {
        return dsu[x] = Find(dsu[x]);   // pass compression
    }   
}

// union x and y set union
void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y) {
        return;
    } else {
        if (dsu[x] < dsu[y]) {
            dsu[x] += dsu[y];
            dsu[y] = x;
        } else {
            dsu[y] += dsu[x];
            dsu[x] = y;
        }
    }
}

// get the union element number
int Count(int x) {
    return -dsu[Find(x)];
}
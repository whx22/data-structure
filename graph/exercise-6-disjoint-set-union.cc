/**
 * @file exercise_disjoint_set_union.cpp
 * @author whx (huxinwang021@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// int dsu[10001];

// // recursion find the set union's root node
// int Find(int x) {
//     if (dsu[x] < 0) {
//         return x;
//     } else {
//         return dsu[x] = Find(dsu[x]);
//     }
// }

// // union x and y set union
// void Union(int x, int y) {
//     x = Find(x);
//     y = Find(y);
//     if (x == y) {
//         return;
//     } else {
//         if (dsu[x] < dsu[y]) {  // set x element number > set y element number
//             dsu[x] += dsu[y];
//             dsu[y] = x;
//         } else {
//             dsu[y] += dsu[y];
//             dsu[x] = y; 
//         }
//     }
// }

// int Count(int x) {
//     return -dsu[Find(x)];
// }

// // disjoint set union exercise 1
// // root node record the number of set element (negative number)
// // other node record its root node index (positive number)
// int dsu[10001];
// // recursion find the set union's root node
// int Find(int x) {
//     if (dsu[x] < 0) {
//         return x;
//     } else {
//         return dsu[x] = Find(dsu[x]);   // pass compression
//     }   
// }
// // union x and y set union
// void Union(int x, int y) {
//     x = Find(x);
//     y = Find(y);
//     if (x == y) {
//         return;
//     } else {
//         if (dsu[x] < dsu[y]) {
//             dsu[x] += dsu[y];
//             dsu[y] = x;
//         } else {
//             dsu[y] += dsu[x];
//             dsu[x] = y;
//         }
//     }
// }
// // get the union element number
// int Count(int x) {
//     return -dsu[Find(x)];
// }


// // disjoint set union exercise 2
// int dsu[10001];

// int Find(int& x) {
//     if (dsu[x] < 0) {
//         return x;
//     } else {
//         return dsu[x] = Find(dsu[x]);
//     }
// }

// void Union(int x, int y) {
//     x = Find(x);
//     y = Find(y);
//     if (x == y) {
//         return;
//     } else {
//         if (dsu[x] < dsu[y]) {
//             dsu[x] += dsu[y];
//             dsu[y] = x;
//         } else {
//             dsu[y] += dsu[x];
//             dsu[x] = y;
//         }
//     }
// }

// int Count(int x) {
//     return -dsu[Find(x)];
// }

// disjoined set union exercise 3
int dsu[10001];

int Find(int x) {
    if (dsu[x] < 0) {
        return x;
    } else {
        return dsu[x] = Find(dsu[x]);
    }
}

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

int Count(int x) {
    return -dsu[Find(x)];
}
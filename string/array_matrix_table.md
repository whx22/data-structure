# array & matrix & table
## array

## matrix 

#### 下三角矩阵
![下三角矩阵](images/5.下三角存储对称矩阵.png)
#### 上三角矩阵
![上三角矩阵](images/6.上三角存储对称矩阵.png)
#### 对角矩阵
![对角矩阵](images/7.对角矩阵.png)
#### 三元组存储稀疏矩阵
![三元组存储稀疏矩阵](images/8.三元组存储稀疏矩阵.png)
```cpp
float tri_mat[MAXSIZE + 1][3];

float val = tri_mat[k][0];
int i = (int)tri_mat[k][1];
int j = (int)tri_mat[k][2];
```
```cpp
typedef struct {
    float val;
    int i, j;
} TriMat;

TriMat tri_mat[MAXSIZE + 1];

float val = tri_mat[k].val;
int i = tri_mat[k].i;
int j = tri_mat[k].j;
```
#### 邻接表存储稀疏矩阵
![邻接表存储稀疏矩阵](images/9.邻接表存储稀疏矩阵.png)
#### 十字链表存储稀疏矩阵
![十字链表存储稀疏矩阵](images/10.十字链表存储稀疏矩阵.png)

## table
![广义表](images/11.广义表.png)
![广义表头尾链表存储结构](images/12.广义表头尾链表存储结构.png)
![广义表扩展线性表存储结构](images/13.广义表扩展线性表存储结构.png)
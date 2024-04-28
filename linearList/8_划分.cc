#include <iostream>
using namespace std;

// 划分 : 以顺序表array[0]下标的值为枢轴
void partition(int array[], int n) {
    int temp;
    int i = 0, j = n - 1;
    temp = array[i];
    while (i < j) {
        while (i < j && array[j] >= temp) {
            --j;
        }
        if (i < j) {
            array[i] = array[j];
            ++i;
        }
        while (i < j && array[i] < temp) {
            ++i;
        }
        if (i > j) {
            array[j] = array[i];
            --j;
        }
    }
    array[i] = temp;
}

// 划分 : 以compare值为枢轴
void partition(int array[], int n, int compare) {
    int temp; 
    int i = 0, j = n - 1;
    temp = array[i];
    while (i < j) {
        while (i < j && array[j] >= compare) {
            --j;
        }
        if (i < j) {
            array[i] = array[j];
            ++i;
        }
        while (i < j && array[i] < compare) {
            ++i;
        }
        if (i < j) {
            array[j] = array[i];
            --j;
        }
    }
    array[i] = temp;
}

// 划分 : 以顺序表array[k]下标的值为枢轴
void partition_k(int array[], int n, int k) {
    int temp;
    int i = 0, j = n - 1;
    temp = array[k];
    array[k] = array[0];
    array[0] = temp;
    temp = array[i];
    while (i < j) {
        while (i < j && array[j] >= temp) {
            --j;
        }
        if (i < j) {
            array[i] = array[j];
            ++i;
        }
        while (i < j && array[i] < temp) {
            ++i;
        }
        if (i < j) {
            array[j] = array[i];
            --j;
        }
    }
    array[i] = temp;
}

// 快速排序


int main(void) {

    return EXIT_SUCCESS;
}
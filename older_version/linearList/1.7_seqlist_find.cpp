// 问题 : 只用一个变量 i，找到 个位正整数arr[]数组 中的 最小值&&最大值
// 解答 : 使用变量的个位保存数字(i % 10), 十位保存下标(i / 10) 

#include <iostream>
using namespace std;

void printSeqList(int arr[], const int& length);

// FunctionName : findMin() 
// Description : find minimum
int findMin(int arr[], const int& length) {
    int i = arr[0];
    while (i / 10 < length) {
        if (i % 10 > arr[i / 10]) {
            i -= i % 10;
            i += arr[i / 10];
        }
        i += 10;
    }
    i %= 10;
    return i;
}

// FunctionName : findMax() 
// Description : find maximum
int findMax(int arr[], const int& length) {
    int i = arr[0];
    while (i / 10 < length) {
        if (i % 10 < arr[i / 10]) {
            i -= i % 10;
            i += arr[i / 10];
        }
        i += 10;
    }
    i %= 10;
    return i;
}

void test_1(void) {
    int arr[10] = {1, 3, 6, 7, 8, 4, 1, 7, 0, 9};
    int length = 10;
    printSeqList(arr, length);

    cout << "the minimum of array is : " << findMin(arr, length) << endl;
    cout << "the maximum of array is : " << findMax(arr, length) << endl;
}

int main(void) {
    test_1();
    return EXIT_SUCCESS;
}

void printSeqList(int arr[], const int& length) {
    for (int i = 0; i < length; ++i) {
        cout << "array[" << i << "] = " << arr[i] << endl;
    }
}
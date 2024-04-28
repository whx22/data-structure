// Reverse Sequential List Algorithm

#include <iostream>
using namespace std;
#define MaxSize 100

void printSeqList(int arr[], const int& length) {
    cout << "The length of the array is : " << length << endl;
    for (int i = 0; i < length; ++i) {
        cout << "array[" << i << "] = " << arr[i] << endl;
    }
}

void Reverse(int arr[], const int& length) {
    int temp;
    for (int i = 0, j = length - 1; i < j; ++i, --j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

/*
 * parameter 1 : the array need to reverse
 * parameter 2 : the array the left index  
 * parameter 3 : the array the right index
 * parameter 4 : the number of need reverse in array
 */
void Reverse(int arr[], const int& left, const int& right, const int& num) {
    int temp;
    // 退出条件为i >= left + num : 逆置num个元素（num < (right - left) / 2）
    // 退出条件为i >= j ： 整表逆置（num >= (right - left) / 2）
    for (int i = left, j = right; i < left + num && i < j; ++i, --j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void test_1(void) {
    int arr[MaxSize] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = 10;
    cout << "Before reverse" << endl;
    printSeqList(arr, length);

    Reverse(arr, 0, length - 1, 1);
    cout << "After reverse" << endl;
    printSeqList(arr, length);
}

int main(void) {
    test_1();
    return EXIT_SUCCESS;
}
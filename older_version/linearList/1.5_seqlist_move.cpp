// 1、将数组前 k 个元素逆置后 移动到 数组后端（要求：数据数据元素不丢失）
// 2、将数组前 k 个元素以原顺序 移动到 数组后端（要求：数据数据元素不丢失）
#include <iostream>
using namespace std;

void printSeqList(int arr[], const int& length) {
    cout << "the length of the array is : " << length << endl;
    for (int i = 0; i < length; ++i) {
        cout << "array[" << i << "] = " << arr[i] << endl;
    }
}

// FunctionName : reverse()
// left : reverse first element
// right: length - 1
// num : the number of needing to reverse element
void reverse(int arr[], const int& left, const int& right, const int& num) {
    int temp;
    for (int i = left, j = right; i < left + num && i < j; ++i, --j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// FunctionName : moveToEnd()
// Calls : reverse()
// Parameter 1 : object SeqList
// Parameter 2 : the length of object SeqList
// Parameter 3 : The number of elements needs to be moved
void moveToEnd(int arr[], const int& length, const int& num) {
    reverse(arr, 0, num - 1, num);
    reverse(arr, 0, length - 1, num);
}


void test_1(void) {
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int length = 10;
    cout << "Before change" << endl;
    printSeqList(arr, length);
    
    // reverse(arr, 0, length - 1, 9);
    // cout << "After change" << endl;
    // printArr(arr, length);

    moveToEnd(arr, length, 4);
    cout << "After move to end" << endl;
    printSeqList(arr, length);
}

int main(void) {
    test_1();
    return EXIT_SUCCESS;
}
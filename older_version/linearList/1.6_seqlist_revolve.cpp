// 旋转数组（左旋数组）
// 时间复杂度：O(n)
// 空间复杂度：O(1)

#include <iostream>
using namespace std;

void printArr(int arr[], const int& length) {
    cout << "length of the array is : " << length << endl;
    for (int i = 0; i < length; ++i) {
        cout << "array[" << i << "] = " << arr[i] << endl;
    }
}

// parameter 1 : array(int)
// parameter 2 : the first element of needing to reverse(before reverse)
// parameter 3 : the last position of element of needing to reverse(after reverse)
// parameter 4 : the number of element need to reverse 
void reverse(int arr[], const int& left, const int& right, const int& num) {
    int temp;
    for (int i = left, j = right; i < left + num && i < j; ++i, --j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// FunctionName : revolveP()
// Calls : reverse()
// Parameter 1 : array(int)
// Parameter 2 : the length of array
// Parameter 3 : left revolve p times
void revolveP(int arr[], const int& length, const int& p) {
    reverse(arr, 0, p - 1, p);
    reverse(arr, p, length - 1, length - p);
    reverse(arr, 0, length - 1, length);
}

void test_1(void) {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = 10;
    cout << "Before revolve" << endl;
    printArr(arr, length);

    revolveP(arr, length, 4);

    cout << "After revolve" << endl;
    printArr(arr, length);
}

int main(void) {
    test_1();
    return EXIT_SUCCESS;
}
// Merge Sequential List Algorithm

#include <iostream>
using namespace std;
#define MaxSize 100

void printSeqList(int arr[], const int& length) {
    cout << "the length of the array is : " << length << endl;
    for (int i = 0; i < length; ++i) {
        cout << "array[" << i << "] = " << arr[i] << endl;
    }
}

/*
 * FunctionName : mergeSeList()
 * Description : merge arrayA and arrayB result stored at arrayC
 */
void mergeSeqList
(int arr_A[], const int& length_A, int arr_B[], const int& length_B, int arr_C[]) {
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < length_A && j < length_B) {
        if (arr_A[i] < arr_B[j]) {
            arr_C[k++] = arr_A[i++];
        }
        else {
            arr_C[k++] = arr_B[j++];
        }
    }
    while (i < length_A) {
        arr_C[k++] = arr_A[i++];
    }
    while (j < length_B) {
        arr_C[k++] = arr_B[j++];
    }
}

void test_1(void) {
    int arr_A[MaxSize] = {1, 2, 5, 6, 7, 8};
    int length_A = 6;
    int arr_B[MaxSize] = {1, 3, 5, 8, 10, 19};
    int length_B = 6;
    int arr_C[MaxSize];
    int length_C = length_A + length_B;

    mergeSeqList(arr_A, length_A, arr_B, length_B, arr_C);

    cout << "After merge" << endl;
    printSeqList(arr_A, length_A);
    printSeqList(arr_B, length_B);
    printSeqList(arr_C, length_C);
}

int main(void) {
    test_1();
    return EXIT_SUCCESS;
}
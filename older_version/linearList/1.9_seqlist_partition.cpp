// The Sequential List Partition Algorithm

#include <iostream>
using namespace std;

void printSeqList(int arr[], const int& length);

// 以第一个元素的值为枢轴，对数组进行划分
void partition(int arr[], const int& length) {
    int i = 0;
    int j = length - 1;
    int temp = arr[0];  // 以arr[0]的值为枢轴

    while (i < j) {
        while (i < j && arr[j] >= temp) {
            --j;
        }
        if (i < j) {
            arr[i] = arr[j];
            ++i;
        }

        while (i < j && arr[i] < temp) {
            ++i;
        }
        if (i < j) {
            arr[j] = arr[i];
            --j;
        }
    }
    arr[i] = temp;
}

// 指定值为枢轴，对数组进行划分
void partition_2(int arr[], const int& length, const int& compare) {
    int i = 0;
    int j = length - 1;
    int temp = compare;
    while (i < j) {
        while (i < j && arr[j] >= compare) {
            --j;
        }
        if (i < j) {
            arr[i] = arr[j];
            ++i;
        }
        while (i < j && arr[i] < compare) {
            ++i;
        }
        if (i < j) {
            arr[j] = arr[i];    
            --j;
        } 
    }
    arr[i] = temp;
}

// 以数组中index为k的值为枢轴，对数组进行划分
void partition_3(int arr[], const int& length, const int& k) {
    int temp = arr[0];
    arr[0] = arr[k];
    arr[k] = temp;

    int i = 0;
    int j = length - 1;
    temp = arr[i];

    while (i < j) {
        while (i < j && arr[j] >= temp) {
            --j;
        }
        if (i < j) {
            arr[i] = arr[j];
            ++i;
        }
        while (i < j && arr[i] < temp) {
            ++i;
        }
        if (i < j) {
            arr[j] = arr[i];
            --j;
        }
    }
    arr[i] = temp;
}

int main(void) {
    int arr[10] = {1, 3, 5, 7, 8, -1, -4, 0, 2, 9};
    int length = 10;
    cout << "Before partition" << endl;
    printSeqList(arr, length);

    partition_3(arr, length, 1);
    cout << "After partition" << endl;
    printSeqList(arr, length);

    return EXIT_SUCCESS;
}

void printSeqList(int arr[], const int& length) {
    cout << "the length of the array is : " << length << endl;
    for (int i = 0; i < length; ++i) {
        cout << "array[" << i << "] = " << arr[i] << endl;
    }
}
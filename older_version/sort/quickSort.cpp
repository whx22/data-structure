#include <iostream>
using namespace std;

void quick_sort(int array[], const int& left, const int& right) {
    if (left < right) {
        int i = left;
        int j = right;
        int pivot = array[left];
        while (i < j) {
            while (i < j && array[j] > pivot) {
                --j;
            }
            if (i < j) {
                array[i] = array[j];
                ++i;
            }
            while (i < j && array[i] <= pivot) {
                ++i;
            }
            if (i < j) {
                array[j] = array[i];
                --j;
            }
        }
        array[i] = pivot;
        quick_sort(array, left, i - 1);
        quick_sort(array, i + 1, right);
    }
}

void printArray(const int array[], const int& length) {
    for (int i = 0; i < length; ++i) {
        cout << array[i] << '\t';
    }
    cout << endl;
}

void test(void) {
    int array[] = {1, 4, 5, 3, 7, 8, 3, 6, 8, 10, 9};
    int length = sizeof(array) / sizeof (array[0]);
    cout << "Before Sort : " << endl;
    printArray(array, length);
    quick_sort(array, 0, length - 1);
    cout << "After Sort : " << endl;
    printArray(array, length);
}

int main(void) {
    test();

    return EXIT_SUCCESS;
}
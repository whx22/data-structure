// Delete Sequential List index(i~j)' element

#include <iostream>
#include <stdexcept>
using namespace std;

void seqListDelete (int SeqList[], int& length, const int& i, const int& j) {
    if (length < j - i + 1 || i < 0 || j > length - 1) {
        throw invalid_argument("error : invalid argument");
    }
    for (int k = 0; k < length - j - 1; ++k) {
        SeqList[i + k] = SeqList[j + 1 + k];
    }
    length -= j - i + 1;
}

void printArr(int Arr[], const int& length) {   
    cout << "length of the array is : "  << length << endl;
    for (int i = 0; i < length; ++i) {
        cout << "array[" << i << "] = " << Arr[i] << endl;
    }
}

int main(void) {
    int Arr[5] = { 1, 2, 3, 4, 5 };
    int length = 5;
    cout << "Before delete" << endl;
    printArr(Arr, length);

    cout << "After delete" << endl;
    try {
        seqListDelete(Arr, length, 0, 4);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
    printArr(Arr, length);

    return EXIT_SUCCESS;
}
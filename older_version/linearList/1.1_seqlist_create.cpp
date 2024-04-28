// Create Sequential List Algorithm

#include <iostream>
#include <stdexcept>
using namespace std;
#define MaxSize 100

void seqListCreate(int SeqList[], int& length) {   
    cin >> length;
    if (length <= 0 || length > MaxSize) {
        throw out_of_range("error: the length is out of range");
    }
    int num;
    for (int i = 0; i < length; ++i) {
        cin >> num;
        SeqList[i] = num;
    }   
}   

void printSeqList(int SeqList[], const int& length) {
    cout << "the length of the array is : "  << length << endl;
    for (int i = 0; i < length; ++i) {
        cout << "array[" << i << "] = " << SeqList[i] << endl;
    }
}

void test_1(void) {
    int SeqList[MaxSize];
    int length = 0;
    try {
        seqListCreate(SeqList, length);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        exit(EXIT_FAILURE);
    }
    printSeqList(SeqList, length);
}

int main(void) {
    test_1();
    return EXIT_SUCCESS;
}
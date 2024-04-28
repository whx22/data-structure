#include <iostream>
#include <exception>
using namespace std;
#define MaxSize 100

// 按index插入
void insertElemByIndex(int SqList[], int& length, const int& index, const int& elem) {
    if (index < 0 || index > length || length >= MaxSize) {
        throw invalid_argument("error : invalid argument");
    }
    else {
        for (int i = 0; i < length - index; ++i) {
            SqList[length - i] = SqList[length - i - 1];
        }
        SqList[index] = elem;
        ++length;
    }
}

// 按position插入
void insertElemByPos(int SqList[], int &length, const int& pos, const int& elem) {
    int index = pos - 1;
    if (index < 0 || index > length || length >= MaxSize) {
        throw invalid_argument("error : invalid argument");
    }
    else {
        for (int i = 0; i < length - index; ++i) {
            SqList[length - i] = SqList[length - i - 1];
        }
        SqList[index] = elem;
        ++length;
    }
}

// 按index删除
void deleteELemByIndex(int SqList[], int& length, const int& index) {
    if (index < 0 || index > length - 1 || length <= 0) {
        throw invalid_argument("error : invalid argument");
    }
    else {
        for (int i = 0; i < length - index - 1; ++i) {
            SqList[index + i] = SqList[index + i + 1];
        }
        --length;
    }
}

// 按position删除
void deleteElemByPos(int SqList[], int& length, const int& pos) {
    int index = pos - 1;
    if (index < 0 || index > length - 1 || length <= 0) {
        throw invalid_argument("error : invalid argument");
    }
    else {
        for (int i = 0; i < length - index - 1; ++i) {
            SqList[index + i] = SqList[index + i + 1];
        }
        --length;
    }
}

void printSeqList(int SeqList[], const int& length) {
    cout << "the length of the array is : " << length << endl;
    for (int i = 0; i < length; ++i) {
        cout << "array[" << i << "] = " << SeqList[i] << endl;
    }
}

int main(void) {
    int SqList[MaxSize] = { 1, 3, 5, 6, 6, 7 };
    int length = 6;

    cout << "Before insert" << endl;
    printSeqList(SqList, length);

    try {
        insertElemByIndex(SqList, length, 6, 9);
        // insertElemByPos(SqList, length, 8, 10);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }

    cout << "After insert, Before delete" << endl;
    printSeqList(SqList, length);

    try {
        deleteELemByIndex(SqList, length, 7);
        // deleteElemByPos(SqList, length, 7);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }

    cout << "After delete" << endl;
    printSeqList(SqList, length);
}
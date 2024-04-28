// String ：the linear list of element is character

#include <iostream>
using namespace std;
#include "string_function.h"

// string_function.cpp test code 
void test_1(void) {
    Str str_1;
    strInit(str_1);
    char temp_1[] = "apple";
    char temp_2[] = "banana";
    strAssign(str_1, temp_1);
    strPrint(str_1);

    cout << "the length of str_1 is : " << strLength(str_1) << endl; 

    Str str_2;
    strInit(str_2);
    strAssign(str_2, temp_2);
    int result = strCompare(str_1, str_2);
    if (result == 0) {
        cout << "str_1 == str_2" << endl;
    } 
    else if (result < 0) {
        cout << "str_1 < str_2" << endl;
    }
    else if (result > 0) {
        cout << "str_1 > str_2" << endl;
    }

    Str str_3;
    strInit(str_3);
    strConcat(str_3, str_1, str_2);
    strPrint(str_3);

    Str str_4;
    strInit(str_4);
    char temp_3[] = "abcdefghijklmnopqrstuvwxyz";
    strAssign(str_4, temp_3);
    Str str_5;
    strInit(str_5);
    getSubstring(str_5, str_4, 0, 26);
    strPrint(str_5);
    clearString(str_5);
    strPrint(str_5);
}

int main(void) {
    test_1();
    return EXIT_SUCCESS;
}
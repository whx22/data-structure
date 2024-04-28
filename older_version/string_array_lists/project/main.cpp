#include <iostream>
using namespace std;
#include "string_function.h"

void test_1(void) {
    Str str_1;
    strInit(str_1);
    char temp[] = "apple";
    strAssign(str_1, temp);
    strPrint(str_1);
}

int main() {
    test_1();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

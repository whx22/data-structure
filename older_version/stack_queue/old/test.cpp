#include <stdio.h>

long int Fact(int n) {
    if (n == 0) return 1;
    else return (n * Fact(n - 1));
}

int main(void) {
    int i, result;
    printf("Please input a integer:");
    scanf("%d", &i);
    result = Fact(i);
    printf("The result is %d", result);

    return 0;
}
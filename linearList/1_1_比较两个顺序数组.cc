#include <iostream>
#include <cmath>
using namespace std;

#define MAXSIZE 100
#define MINIMUM 0.0001

int compare(float A[], int An, float B[], int Bn) {
    int i = 0;
    while (i < An || i < Bn) {
        if (fabs(A[i] - B[i]) < MINIMUM) {
            ++i;
        } else {
            break;
        }
    }
    if (i > An && i > Bn) {
        return 0;
    } else if ((i >= An && i < Bn) || A[i] < B[i]) {
        return -1;
    } else {
        return 1;
    }
}

int main(void) {
    float A[MAXSIZE] = { 1, 2, 3, 4, 5 };
    int An = 5;
    float B[MAXSIZE] = { 1, 2, 3, 4, 5, 6 };
    int Bn = 6;
    cout << compare(A, 5, B, 6) << endl;
    return EXIT_SUCCESS;
}
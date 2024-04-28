#include <iostream>
#include <cmath>
using namespace std;

#define Min 0.00001

int compare(double A[], int An, double B[], int Bn) {
    int i = 0;
    while (i < An && i < Bn) {
        if (fabs(A[i] - B[i]) < Min) {
            ++i;
        }
        else {
            break;
        }
    }

    if (i >= An && i >= Bn) {
        return 0;
    }
    else if ((i >= An && i < Bn) || A[i] < B[i]) {
        return -1;
    }
    else {
        return 1;
    }
}

int main(void) {
    double A[5] = {1, 2, 3, 4, 5};
    double B[5] = {1, 2, 3, 4, 5};

    int result = compare(A, 5, B, 5);

    if (result == 0) {
        cout << "A == B" << endl;
    }
    else if (result < 0) {
        cout << "A < B" << endl;
    }
    else {
        cout << "A > B" << endl;
    }
}
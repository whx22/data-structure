#include <iostream>
#include <cmath>

const int MAXSIZE = 100;
const double MINIMUM = 0.0001;

int compare(const int *&A, const int &AN, const int *&B, const int &BN) {
    int i = 0;
    while (i < AN || i < BN) {
        if (fabs(A[i] - B[i]) < MINIMUM) {
            ++i;
        } else {
            break;
        }
    }
    if (i > AN && i > BN) {
        return 0;
    } else if ((i >= AN && i < BN) || (A[i] < B[i])) {
        return -1;
    } else {
        return 1;
    }
}
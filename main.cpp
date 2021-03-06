#include <iostream>
#include <omp.h>

#define n 2

using namespace std;

void parallel_mul(const unsigned* X, const unsigned* Y, size_t N, unsigned* Z) {
    unsigned carry;
    for (int j = (int)N - 1; j >= 0; --j)
        for (int i = (int)N - 1; i >= 0; --i) {
            carry = Z[i + j + 1] + X[i] * Y[j];
            Z[i + j + 1] = carry % 10;
            carry /= 10;
            Z[i + j] = Z[i + j] + carry;
        }
}

int main() {
    unsigned X[n], Y[n], Z[2 * n];

    for (auto &digit: Z) digit = 0;

    for (unsigned int & i : X) {
        i = rand() % 10;
        cout << i;
    }

    cout << " * ";

    for (unsigned int & i : Y) {
        i = rand() % 10;
        cout << i;
    }

    cout << endl << "============================================ " << endl;
    parallel_mul(X, Y, n, Z);
    for (auto digit: Z) cout << digit;
}

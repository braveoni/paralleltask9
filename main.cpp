#include <iostream>
#include <omp.h>

#define n 1000

using namespace std;

void parallel_mul(const unsigned* X, const unsigned* Y, size_t N, unsigned* Z) {
    unsigned carry = 0;
    for (int j = (int)N - 1; j >= 0; --j)
        for (int i = (int)N - 1; i >= 0; --i) {
            carry = Z[i + j + 1] ? Z[i + j + 1] + X[i] * Y[j] + carry : X[i] * Y[j] + carry;
            Z[i + j + 1] = carry % 10;
            carry /= 10;
        }
}

int main() {
    unsigned X[n], Y[n], Z[2 * n - 1];

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

#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

void parallel_mul(const unsigned* X, const unsigned* Y, size_t N, unsigned* Z) {
    unsigned carry = 0;
    for (int j = (int)N - 1; j >= 0; --j)
        for (int i = (int)N - 1; i >= 0; --i) {
            carry = Z[i + j + 1] + X[i] * Y[j] + carry;
            Z[i + j + 1] = carry % 10;
            carry /= 10;
        }
    cout << endl;
}


int main() {
    unsigned X[3] = {1, 2, 3}, Y[3] = {3, 2, 1}, Z[6] = {0};
    parallel_mul(X, Y, 3, Z);
    for (auto digit: Z) cout << digit << ' ';
}

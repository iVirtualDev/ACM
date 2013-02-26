#include <iostream>
#include <cassert>

using namespace std;

typedef unsigned long long integer;

struct Matrix {
    integer data[4];
};

Matrix operator*(const Matrix& left, const Matrix& right) {
    Matrix result;
    result.data[0] = left.data[0]*right.data[0] + left.data[1]*right.data[2];
    result.data[1] = left.data[0]*right.data[1] + left.data[1]*right.data[3];
    result.data[2] = left.data[2]*right.data[0] + left.data[3]*right.data[2];
    result.data[3] = left.data[2]*right.data[1] + left.data[3]*right.data[3];
    return result;
}

void modulize(Matrix& m, integer k) {
    for (int i = 0; i < 4; ++i) {
	m.data[i] = m.data[i] % k;
    }
}

Matrix mat_k(const Matrix& m, integer n, integer k) {
    assert(n >= 1);
    Matrix result;
    if (n == 1) {
	result = m;
    } else if (n % 2 == 0) {
	Matrix some = mat_k(m, n / 2, k);
	result = some * some;
    } else {
        assert(n - 1 >= 2);
        result = mat_k(m, n - 1, k) * m;
    }
    modulize(result, k);
    return result;
}

integer fib_k(int n, int k) {
    assert(n >= 1);
    assert(k >= 1);
    if (n == 1) {
	return 1 % k;
    }
    Matrix p;
    p.data[0] = p.data[1] = p.data[2] = 1;
    p.data[3] = 0;
    Matrix p_n_1 = mat_k(p, n - 1, k);
    return p_n_1.data[0];
}

int main() {
    integer N, K;
    cin >> N >> K;

    integer result = fib_k(N, K);
    cout << result << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXM = 256;
const int MOD = 1e9;

class Matrix {
public:
	ll mat[MAXM][MAXM];

	Matrix() {
		memset(mat, 0, sizeof(ll) * MAXM * MAXM);
	}

	Matrix operator*(Matrix m) {
		Matrix a = *(new Matrix());
		for (int k = 0; k < MAXM; ++k) 
			for (int i = 0; i < MAXM; ++i)
				for (int j = 0; j < MAXM; ++j) 
					a.mat[i][j] = (a.mat[i][j] + mat[i][k] * m.mat[k][j]) % MOD;
		return a;
	}
};

Matrix pow(Matrix b, ll n) {
	Matrix a = *(new Matrix());
	for (int i = 0; i < MAXM; ++i) a.mat[i][i] = 1;
	while (n) {
		if (n&1) a = a * b;
		b = b * b;
		n >>= 1;
	}
	return a;
}

int fib(int n) {
    int a = 1;
    int b = 2;
    for (int i = 0; i < n; i++) {
        int tmp = a + b;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {
    ll m, n; cin >> m >> n;
	Matrix M = *(new Matrix());

	int fibb[9]; fibb[0] = 1;
	for (int i = 1; i <= 8; ++i) fibb[i] = fib(i - 1);

	for (int i = 0; i < (1 << m); ++i) {
		for (int j = 0; j < (1 << m); ++j) {

			int num1 = i, num2 = j, ct = 0;
			ll ways = 1; bool shouldBeZero = 0;

			for (int k = m - 1; k >= 0; --k) {
				int bit = (num1>>k)&1, topbit = (num2>>k)&1;
				if (topbit && bit) {
					shouldBeZero = 1; break;
				}
				else if (topbit ^ bit) {
					ways = (ways * fibb[ct]) % MOD; ct = 0;
				}
				else ct++;
			}

			ways = (ways * fibb[ct]) % MOD;
			M.mat[i][j] = shouldBeZero ? 0 : ways;
		}
	}

	M = pow(M, n);

	Matrix v = *(new Matrix());
	v.mat[0][0] = 1;
	
	M = v * M;
	cout << M.mat[0][0] % MOD;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXM = 256;
const int MOD = 1e9;

// matrix template
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

// matrix exponentiation
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

int main() {
    ll m, n; cin >> m >> n;
	Matrix M = *(new Matrix());

	// init fibonacci array
	int fibb[9] = {1, 1, 2, 3, 5, 8, 13, 21, 34};

	for (int i = 0; i < (1 << m); ++i) {
		for (int j = 0; j < (1 << m); ++j) {

			int num1 = i, num2 = j, ct = 0;
			ll ways = 1; bool shouldBeZero = 0;

			for (int k = m - 1; k >= 0; --k) {

				// check both bits for i -> j

				int bit = (num1>>k)&1, topbit = (num2>>k)&1;

				// both top and bottom bit can't be 1
				// count all bits with both 0s and multiply it with fib at the separators
				if (topbit && bit) {
					shouldBeZero = 1; break;
				}
				else if (topbit ^ bit) {
					ways = (ways * fibb[ct]) % MOD; ct = 0;
				}
				else ct++;
			}

			// final multiply
			ways = (ways * fibb[ct]) % MOD;

			// init matrix dp state
			M.mat[i][j] = shouldBeZero ? 0 : ways;
		}
	}

	// take n timesteps
	M = pow(M, n);
	cout << M.mat[0][0] % MOD;

    return 0;
}
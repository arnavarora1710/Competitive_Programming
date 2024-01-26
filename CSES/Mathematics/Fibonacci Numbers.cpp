#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
int n;
const int MOD = 1e9 + 7, MAXM = 3;
typedef long long ll;

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

void solve() {
    cin >> n;
    Matrix A = *(new Matrix());
    if (n <= 1) cout << n;
    else if (n == 2) cout << 1;
    else {
        A.mat[0][0] = A.mat[0][1] = 1;
        A.mat[1][0] = A.mat[2][1] = 1;
        A = pow(A, n - 2);
        cout << (A.mat[0][0] + A.mat[0][1]) % MOD;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
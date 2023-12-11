#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = (a); i < (b); ++i) 
#define rep0(i, b) for (int i = 0; i < (b); ++i)
#define sz(x) ((int) (x).size())
template <typename T> using V = vector<T>;
template <typename T> using VV = V<vector<T>>;

// Matrix struct
typedef __int128 T;
T mod = 1e9;
struct M {
    // internal matrix
    VV<T> a;
    // matrix size
    int n;
    // grid initializer
    M(VV<T>& x) : a(x), n(sz(x)) {}
    // identity initializer
    M(int n): a(VV<T>(n, V<T>(n, 0))), n(n) {
        rep0(i, n) a[i][i] = 1;
    }

    // * operator - basic n^3 matrix mult
    M operator*(M& o) {
        VV<T> ret(n, V<T>(n));
        // cache-optimized version of matrix mult - ~2x faster than naive i,j,k
        rep0(i, n) {
            rep0(k, n) {
                rep0(j, n) {
                    // If you can afford to not mod every time, it's decently fast
                    ret[i][j] = (ret[i][j] + a[i][k] * o.a[k][j]); 
                }
            }
        }
        rep0(i, n) rep0(j, n) ret[i][j] %= mod;
        return M(ret);
    } 

    // + operator - pairwise addition
    M operator+(M& o) {
        VV<T> ret(n, V<T>(n));
        rep0(i, n) rep0(j, n) ret[i][j] = (a[i][j] + o.a[i][j]) % mod;
        return ret;
    }

    // Mod the entire matrix by mod
    M operator%(T m) {
        rep0(i, n) {
            rep0(j, n) {
                a[i][j] %= m;
            }
        }
        return *this;
    }

    // * operator for vector multiplication (Ab)
    V<T> operator*(V<T>& b) {
        V<T> ret(n);
        rep0(i, n) {
            T sum = 0;
            rep0(j, n) {
                sum += a[i][j] * b[j];
            }
            ret[i] = sum % mod;
        }
        return ret;
    } 

    // Binary exponentiation, with matrices instead of scalars
    M operator^(ll p) {
        M x(a);
        // x = x % mod;  // note: m * m must be less than 2^63 to avoid ll overflow
        M res(n);
        while (p) {
            if (p & 1) { res = res * x; }
            x = x * x;
            p >>= 1;
        }
        return res;
    }
};

int main() {
    ll m, n; cin >> m >> n;
	VV<T> mat(1<<m, V<T>(1<<m));

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
					ways = (ways * fibb[ct]) % mod; ct = 0;
				}
				else ct++;
			}

			// final multiply
			ways = (ways * fibb[ct]) % mod;

			// init matrix dp state
			mat[i][j] = shouldBeZero ? 0 : ways;
		}
	}
	
	M matr = *(new M(mat));
	// take n timesteps
	matr = matr ^ n;
	cout << (ll) (matr.a[0][0] % mod);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int t, n, m, fact[1000005];

int pw(int a, int b) {
    int res = 1;
    while (b) {
        if (b&1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int inv(int x) {
    return pw(x, mod - 2);
}

signed main() {
    cin >> t;
    fact[0] = fact[1] = 1;
    for (int i = 2; i < 1000005; ++i) fact[i] = (fact[i - 1] * i) % mod;
    while (t--) {
        cin >> n >> m;
        cout << ((fact[n] * inv(fact[m])) % mod * inv(fact[n - m])) % mod << endl;
    }
    return 0;
}
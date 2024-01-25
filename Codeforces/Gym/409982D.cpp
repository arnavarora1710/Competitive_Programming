// https://codeforces.com/gym/409982/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n, a[1005];

const int N = 10000005, mod = 1e9 + 7;
int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b&1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
int fac[N], ifac[N];
void init() {
	ifac[0] = fac[0] = 1;
	for(int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % mod;
	ifac[N - 1] = power(fac[N - 1], mod - 2);
	for(int i = N - 2; i; i--) ifac[i] = ifac[i + 1] * (i + 1) % mod;
}
int ncr(int n, int r) {
	if(n < 0 || n < r || r < 0) return 0;
	return fac[n] * ifac[n - r] % mod * ifac[r] % mod;
}

void solve() {
    cin >> n; int zero = 0, pos = 0, neg = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (!a[i]) zero++;
        else if (a[i] > 0) pos++;
        else neg++;
    }
    int ans_0 = 0, ans_pos = power(2, pos) - 1, ans_neg = 0;
    for (int tog = 1; tog <= zero; ++tog) {
        int mult = (tog&1 ? 1 : -1);
        ans_0 = ((ans_0 + mult * ((ncr(zero, tog) * power(2, n - tog))) + mod) % mod) % mod;
    }
    for (int negTaken = 2; negTaken <= neg; negTaken += 2) {
        ans_pos = (ans_pos + (power(2, pos) * ncr(neg, negTaken)) % mod) % mod; 
    }
    for (int negTaken = 1; negTaken <= neg; negTaken += 2) {
        ans_neg = (ans_neg + (power(2, pos) * ncr(neg, negTaken)) % mod) % mod; 
    }
    cout << ans_pos << " " << ans_neg << " " << ans_0 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    init();

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
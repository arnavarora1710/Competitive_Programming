// https://codeforces.com/contest/1985/problem/G
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18, mod = 1e9 + 7;
int l, r, k;

int power(int x, int y) {
    int res = 1;
    while (y) {
        if (y&1) res = (res * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return res;
}

int inv(int x) {
    return power(x, mod - 2);
}

void solve() {
    cin >> l >> r >> k;
    int i = 9 / k;
    int ans = (i * power(i + 1, l)) % mod * (power(i + 1, r - l) - 1) % mod * inv(i) % mod;
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

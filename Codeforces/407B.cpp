// https://codeforces.com/problemset/problem/407/B
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 1005, inf = 1e18, mod = 1e9 + 7;
int n, a[maxn];

void solve() {
    cin >> n; for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (a[i] == i) dp[i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = a[i]; j < i; ++j) dp[i] = (dp[i] + dp[j]) % mod;
        if (i != a[i]) dp[i] = (dp[i] + i - a[i] + 1) % mod;
    }
    int ans = n;
    for (int i = 1; i <= n; ++i) ans = (ans + dp[i]) % mod;
    cout << ans;
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

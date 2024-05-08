// https://codeforces.com/contest/1829/problem/H
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
const int mod = 1e9 + 7;
int n, k, a[maxn];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int>(64));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 64; ++j) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            dp[i][j & a[i]] = (dp[i][j & a[i]] + dp[i - 1][j]) % mod;
        }
        dp[i][a[i]] = (dp[i][a[i]] + 1) % mod;
    }
    int ans = 0;
    for (int i = 0; i < 64; ++i) {
        if (__builtin_popcount(i) == k) 
            ans = (ans + dp[n][i]) % mod;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
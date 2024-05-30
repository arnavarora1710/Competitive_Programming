// https://codeforces.com/contest/1051/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 2e3 + 5, inf = 1e18, mod = 998244353;
int n, k, dp[maxn][maxn][2][2];

void solve() {
    cin >> n >> k;
    // 0 - white, 1 - black
    dp[1][1][0][0] = dp[1][1][1][1] = 1;
    dp[1][2][0][1] = dp[1][2][1][0] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[i][j][0][0] = (dp[i - 1][j][0][0] + dp[i - 1][j][0][1] + dp[i - 1][j][1][0] + dp[i - 1][j - 1][1][1]) % mod;
            dp[i][j][0][1] = (dp[i - 1][j - 1][0][0] + dp[i - 1][j][0][1] + (j >= 2 ? dp[i - 1][j - 2][1][0] : 0) + dp[i - 1][j - 1][1][1]) % mod;
            dp[i][j][1][0] = (dp[i - 1][j - 1][0][0] + (j >= 2 ? dp[i - 1][j - 2][0][1] : 0) + dp[i - 1][j][1][0] + dp[i - 1][j - 1][1][1]) % mod;
            dp[i][j][1][1] = (dp[i - 1][j - 1][0][0] + dp[i - 1][j][0][1] + dp[i - 1][j][1][0] + dp[i - 1][j][1][1]) % mod;
        }
    }
    int ans = (dp[n][k][0][0] + dp[n][k][1][0] + dp[n][k][0][1] + dp[n][k][1][1]) % mod;
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

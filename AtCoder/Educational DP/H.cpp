#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 1e3 + 5, inf = 1e18, mod = 1e9 + 7;
int n, m, dp[maxn][maxn];
char a[maxn][maxn];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) cin >> a[i][j];
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i || j) {
                char c1 = (i ? a[i - 1][j] : '#');
                char c2 = (j ? a[i][j - 1] : '#');
                if (c1 != '#') dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                if (c2 != '#') dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
            }
        }
    }
    cout << dp[n - 1][m - 1];
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

// https://codeforces.com/problemset/problem/467/C
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 5e3 + 5, inf = 1e18;
int n, m, k, a[maxn], p[maxn], dp[maxn][maxn];

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) p[i] = p[i - 1] + a[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (i >= m)
                dp[i][j] = max(dp[i - 1][j], dp[i - m][j - 1] + p[i] - p[i - m]);
        }
    }
    cout << dp[n][k];
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

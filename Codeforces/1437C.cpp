// https://codeforces.com/problemset/problem/1437/C
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e2 + 5, inf = 1e18;
int n, a[maxn], dp[maxn][2 * maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < maxn; ++i)
        for (int j = 0; j < 2 * maxn; ++j) dp[i][j] = inf;
    dp[0][0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 2 * n; ++j) {
            if (i && j)
                dp[i][j] = dp[i - 1][j - 1] + abs(a[i - 1] - j);
            if (j)
                dp[i][j] = min(dp[i][j], dp[i][j - 1]);
        }
    }
    cout << dp[n][2 * n - 1] << '\n'; 
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

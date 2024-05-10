// https://codeforces.com/contest/1969/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 3e5 + 5, inf = 1e18;
int n, k, a[maxn];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, inf));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            int mn = inf;
            for (int kk = 0; kk + j <= k && kk + i < n; ++kk) {
                mn = min(mn, a[i + kk]);
                dp[i + kk + 1][j + kk] = min(dp[i + kk + 1][j + kk], dp[i][j] + (kk + 1) * mn);
            }
        }
    }
    int ans = inf; for (int i = 0; i <= k; ++i) ans = min(ans, dp[n][i]);
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
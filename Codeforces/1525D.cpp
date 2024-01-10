// https://codeforces.com/problemset/problem/1525/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define MULTI_TEST (0)
int n, a[5005];

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> ones; for (int i = 0; i < n; ++i) if (a[i]) ones.push_back(i);
    int sz = ones.size();
    vector<vector<int>> dp(n + 1, vector<int>(sz + 1, 2 * n * n));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= sz; ++j) {
            if (dp[i][j] == 2 * n * n) continue;
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            if (j < sz && !a[i]) {
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(ones[j] - i));
            }
        }
    }
    cout << dp[n][sz];
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
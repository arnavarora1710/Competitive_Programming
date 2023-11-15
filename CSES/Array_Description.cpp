#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int a[100001];

int main() {
    int n, m; cin >> n >> m; for (int i = 0; i < n; ++i) cin >> a[i];

    // dp(i, j): number of arrays for which ith element = j
    int dp[n][m + 1]; fill(dp[0], dp[0] + m + 1, 0);

    for (int i = 1; i <= m; ++i)
        if (i == a[0] || !a[0]) dp[0][i] = 1;
    
    for (int i = 1; i < n; ++i) {
        fill(dp[i], dp[i] + m + 1, 0);
        for (int j = 1; j <= m; ++j) {
            if (a[i] && j != a[i]) continue;
            dp[i][j] = dp[i - 1][j];
            if (j - 1) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
            if (j + 1 <= m) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
        }
    }

    for (int i = 1; i <= m; ++i) dp[n - 1][i] = (dp[n - 1][i] + dp[n - 1][i - 1]) % MOD;
    cout << dp[n - 1][m];

    return 0;
}
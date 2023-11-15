#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int a[100001];

int main() {
    int n, m; cin >> n >> m; for (int i = 0; i < n; ++i) cin >> a[i];

    // dp(i, j): number of arrays for which ith element = j
    vector<vector<int>> dp(n, vector<int>(m + 1));

    if (a[0]) 
        dp[0][a[0]] = 1;
    else
        for (int i = 1; i <= m; ++i) dp[0][i] = 1;
    
    for (int i = 1; i < n; ++i) {
        if (a[i]) {
            dp[i][a[i]] = dp[i - 1][a[i]];
            if (a[i] - 1) dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][a[i] - 1]) % MOD;
            if (a[i] + 1 <= m) dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][a[i] + 1]) % MOD;
        }
        else {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j - 1) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                if (j + 1 <= m) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= m; ++i) ans = (ans + dp[n - 1][i]) % MOD;

    cout << ans;

    return 0;
}
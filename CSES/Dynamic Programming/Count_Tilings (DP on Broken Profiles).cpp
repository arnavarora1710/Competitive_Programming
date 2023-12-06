#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int n, m, dp[1001][11][1024];
// dp(i, j, profile): number of ways to fill the first i columns and 
// j rows (squares) with profile sticking out

int main() {
    cin >> n >> m;
    memset(dp, 0, sizeof(dp)); dp[0][n][0] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int profile = 0; profile < (1 << n); ++profile)
            dp[i][0][profile] = dp[i - 1][n][profile];
        for (int j = 1; j <= n; ++j) {
            for (int profile = 0; profile < (1 << n); ++profile) {
                if (profile & (1 << (j - 1))) {
                    dp[i][j][profile] = (dp[i][j][profile] + dp[i][j - 1][profile ^ (1 << (j - 1))]) % MOD;
                }
                else {
                    dp[i][j][profile] = (dp[i][j][profile] + dp[i][j - 1][profile | (1 << (j - 1))]) % MOD;
                    if (j > 1 && !(profile & (1 << (j - 2)))) {
                        dp[i][j][profile] = (dp[i][j][profile] + dp[i][j - 2][profile]) % MOD;
                    }
                }
            }
        }
    }
    cout << dp[m][n][0];
    return 0;
}
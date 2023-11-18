#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long dp[501][65526];

int main() {
    int n; cin >> n; int sum = (n * (n + 1)) >> 1;
    if (sum&1) cout << 0;
    else {
        int target = sum >> 1; memset(dp, 0, sizeof(long) * (n + 1) * (target + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= target; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j - i >= 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % MOD;
            }
        }
        cout << (dp[n][target] * 500000004) % MOD;
    }

    return 0;
}
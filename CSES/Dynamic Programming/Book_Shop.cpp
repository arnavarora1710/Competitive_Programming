#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x; cin >> n >> x; 
    int h[n], s[n]; 
    for (int i = 0; i < n; ++i) cin >> h[i];
    for (int i = 0; i < n; ++i) cin >> s[i];

    // dp(i, j): max pages having considered first i books and <= j cost
    // basic knapsack!
    int dp[n + 1][x + 1];
    for (int i = 0; i <= n; ++i) fill(dp[i], dp[i] + x + 1, 0);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= x; ++j) {
            if (j - h[i - 1] >= 0) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - h[i - 1]] + s[i - 1]);
            else dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n][x];
    return 0;
}
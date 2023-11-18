#include <bits/stdc++.h>
using namespace std;
long a[5000];
long dp[5000][5000];

int main() {
    int n; cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) dp[i][i] = a[i];
    for (int i = 0; i < n - 1; ++i) dp[i][i + 1] = max(a[i], a[i + 1]);

    for (int len = 2; len <= n; ++len)
        for (int i = 0; i + len < n; ++i) {
            long choice1 = min(dp[i + 1][i + len - 1] + a[i], dp[i + 2][i + len] + a[i]);
            long choice2 = min(dp[i + 1][i + len - 1] + a[i + len], dp[i][i + len - 2] + a[i + len]);
            dp[i][i + len] = max(choice1, choice2);
        }

    cout << dp[0][n - 1];

    return 0;
}
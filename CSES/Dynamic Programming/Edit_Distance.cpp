#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();
    if (n > m) swap(a, b), swap(n, m);

    // dp(i, j): min operations to edit a[0...i] to b[0...j]
    int dp[n][m]; memset(dp, 0, sizeof(int) * n * m);

    for (int i = 0; i < m; ++i) dp[0][i] = i + (b[i] != a[0] ? a[0] != b[0] : 0);
    for (int i = 1; i < n; ++i) dp[i][0] = i + (a[0] != b[0]);

    for (int i = 1; i < n; ++i) 
        for (int j = 1; j < m; ++j) 
            dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + (a[i] != b[j])));

    cout << dp[n - 1][m - 1];
    return 0;
}
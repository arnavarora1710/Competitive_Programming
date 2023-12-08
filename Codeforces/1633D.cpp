// https://codeforces.com/problemset/problem/1633/D
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 1;
int t, n, k, b[MAXN], c[MAXN], dp[MAXN], dp1[MAXN][12 * MAXN];

int main() {
    cin >> t; 
    dp[1] = 0; for (int i = 2; i < MAXN; ++i) dp[i] = 1e9;
    for (int i = 1; i < MAXN; ++i) 
        for (int j = 1; j <= i; ++j) 
            dp[i + i / j] = min(dp[i + i / j], dp[i] + 1);
    while (t--) {
        cin >> n >> k; k = min(k, 12 * n);
        
        for (int i = 0; i < n; ++i) cin >> b[i];
        for (int i = 0; i < n; ++i) cin >> c[i];

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp1[i][j] = dp1[i - 1][j];
                if (j >= dp[b[i - 1]])
                    dp1[i][j] = max(dp1[i - 1][j], dp1[i - 1][j - dp[b[i - 1]]] + c[i - 1]);
            }
        }
        int ans = 0; for (int i = 0; i <= k; ++i) ans = max(ans, dp1[n][i]);
        cout << ans << endl; 
    }
    return 0;
}
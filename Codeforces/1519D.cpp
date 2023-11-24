// https://codeforces.com/problemset/problem/1519/D
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n; ll a[n], b[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    ll prod = 0;
    for (int i = 0; i < n; ++i) prod += a[i] * b[i];

    ll dp[n][n]; ll ans = prod;
    for (int i = 0; i < n; ++i) dp[i][i] = prod;
    for (int i = 0; i < n - 1; ++i) {
        dp[i][i + 1] = prod + a[i] * b[i + 1] + a[i + 1] * b[i] - a[i] * b[i] - a[i + 1] * b[i + 1];
        ans = max(ans, dp[i][i + 1]);
    }
    
    for (int len = 2; len < n; ++len) {
        for (int i = 0; i + len < n; ++i) {
            dp[i][i + len] = dp[i + 1][i + len - 1] + a[i] * b[i + len] + a[i + len] * b[i] - a[i] * b[i] - a[i + len] * b[i + len];
            ans = max(ans, dp[i][i + len]);
        }
    }

    cout << ans;
    return 0;
}
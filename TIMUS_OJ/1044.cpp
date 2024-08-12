#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (0)
int n, dp[5][37];

void solve() {
    cin >> n; n >>= 1;
    for (int i = 0; i <= 9; ++i)
        dp[1][i] = 1;
    for (int i = 2; i <= n; ++i)
        for (int j = 0; j <= 36; ++j)
            for (int k = 0; k <= 9 && j >= k; ++k)
                dp[i][j] += dp[i - 1][j - k];
    int ans = 0;
    for (int i = 0; i <= 36; ++i) 
        ans += (dp[n][i] * dp[n][i]);
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

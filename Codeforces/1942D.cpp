// https://codeforces.com/contest/1942/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
// dp(i, j) : j^th maximum value of beauty ending at i
// store where you started as well
// then dp(i, j) = max over all j (dp(i - 1, j) + a[st][i])
const int inf = 1e18;
int n, k;
// pi dp[1005][5005];
vector<int> a[1005];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        a[i].clear();
        a[i].resize(n - i + 1);
        for (int j = 1; j <= n - i + 1; ++j) cin >> a[i][j];
    }
    for (int i = 0; i < 1005; ++i) {
        for (int j = 0; j < 5005; ++j) dp[i][j] = {-inf, -1};
    }
    int val = max(0LL, a[1][1]);
    int starter = (val ? 0 : -1);
    for (int i = 1; i <= n; ++i) dp[1][i] = {val, starter};
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= k; ++k) {
            int mx = 0, st = -1;
            for (int jj = 1; jj <= j; ++jj) {
                if (mx > dp[i - 1][jj].f) {
                    mx = dp[i - 1][jj].f;
                    st = dp[i - 1][jj].s;
                }
            }
            dp[i][j].f = mx + a[st][i].f;
        }
        // for (int j = 0; j < k; ++j) {
        //     dp[i][j].f = max(dp[i - 1][j].f, mx + a[]);
        // }
    }
    for (int i = 1; i <= k; ++i) {
        int mx = 0;
        for (int j = 1; j <= n; ++j) mx = max(mx, dp[j][i].f);
        cout << mx << " ";
    }
    
    // cout << dp[n - 1][i] << " ";
    cout << endl;
    // int mx = a[0][0]; dp[0][0] = mx;
    // for (int i = 1; i < n; ++i)
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
// https://codeforces.com/contest/1989/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 1e6 + 5, inf = 1e18;
int n, m, a[maxn], b[maxn], c[maxn];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < m; ++i) cin >> c[i];
    int mx = *(max_element(a, a + n));
    vector<int> dp(mx + 1, inf), dp1(mx + 1, 0);
    for (int i = 0; i < n; ++i)
        dp[a[i]] = min(dp[a[i]], a[i] - b[i]);
    for (int i = 1; i <= mx; ++i)
        dp[i] = min(dp[i], dp[i - 1]);
    for (int i = 1; i <= mx; ++i)
        if (i >= dp[i]) dp1[i] = 2 + dp1[i - dp[i]];
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int tot = c[i];
        if (tot > mx) {
            int k = (tot - mx) / dp[mx] + 1;
            ans += 2 * k;
            tot -= k * dp[mx];
        }
        ans += dp1[tot];
    }
    cout << ans;
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

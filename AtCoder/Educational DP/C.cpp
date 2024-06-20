#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
int n, a[maxn], b[maxn], c[maxn], dp[maxn][3];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i] >> c[i];
    for (int i = 1; i <= n; ++i) {
	for (int j = 0; j < 3; ++j) {
	    if (j) dp[i][0] = max(dp[i][0], dp[i - 1][j] + a[i]);
	    if (j != 1) dp[i][1] = max(dp[i][1], dp[i - 1][j] + b[i]);
	    if (j != 2) dp[i][2] = max(dp[i][2], dp[i - 1][j] + c[i]);
	}
    }
    cout << max(dp[n][0], max(dp[n][1], dp[n][2]));
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

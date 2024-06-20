#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 105, maxk = 1e5 + 5, inf = 1e18;
int n, k, a[maxn], b[maxn], dp[maxn][maxk];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
    for (int i = 1; i <= n; ++i) {
	for (int j = 0; j <= k; ++j) {
	    dp[i][j] = dp[i - 1][j];
	    if (j - a[i] >= 0)
		dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]] + b[i]);
	}
    }
    cout << dp[n][k];
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 105, maxv = 2e5 + 5, inf = 1e18;
int n, k, a[maxn], b[maxn];
pi dp[maxv];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
    dp[0] = {1, 0};
    for (int i = 1; i < maxv; ++i) dp[i] = {0, inf};
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
	for (int j = maxv; j >= 1; --j) {
	    if (j - b[i] >= 0 && dp[j - b[i]].f && dp[j - b[i]].s + a[i] <= k) {
		dp[j].f = 1;
		dp[j].s = min(dp[j].s, dp[j - b[i]].s + a[i]);
	    }
	}
    }
    for (int i = 0; i < maxv; ++i)
	if (dp[i].f) ans = i;
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

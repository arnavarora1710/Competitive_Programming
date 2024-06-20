#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 3e3 + 5, inf = 1e18;
int n;
double a[maxn], dp[maxn][maxn];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
	for (int j = 0; j <= i; ++j) {
	    dp[i][j] = dp[i - 1][j] * (1 - a[i]);
	    if (j) dp[i][j] += dp[i - 1][j - 1] * a[i];
	}
    }
    double ans = 0;
    for (int i = (n + 1) / 2; i <= n; ++i) ans += dp[n][i];
    cout << fixed << setprecision(15) << ans;
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

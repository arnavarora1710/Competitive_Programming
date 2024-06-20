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
int n, a[maxn], dp[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) {
	int c1 = dp[i - 1] + abs(a[i] - a[i - 1]);
	int c2 = (i >= 2 ? dp[i - 2] + abs(a[i] - a[i - 2]) : inf);
	dp[i] = min(c1, c2);
    }
    cout << dp[n - 1];
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

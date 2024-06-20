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
int n, m, x, y, vis[maxn], deg[maxn], dp[maxn];
vector<int> adj[maxn];

int dfs(int nn) {
    vis[nn] = true;
    int ret = 0;
    for (auto cc : adj[nn]) {
	if (!vis[cc]) dfs(cc);
	ret = max(ret, dp[cc] + 1);
    }
    dp[nn] = max(dp[nn], ret); 
    return dp[nn];
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
	cin >> x >> y;
	adj[x].push_back(y);
	deg[y]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
	if (!vis[i] && !deg[i])
	    ans = max(ans, dfs(i));
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

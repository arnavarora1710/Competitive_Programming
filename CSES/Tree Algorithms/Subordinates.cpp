#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
const int maxn = 200005;
int n, x, ans[maxn], vis[maxn]; vector<int> adj[maxn];

int dfs(int nn) {
    vis[nn] = true;
    for (auto& xx : adj[nn]) if (!vis[xx]) ans[nn] += 1 + dfs(xx);
    return ans[nn];
}

void solve() {
    cin >> n;
    for (int i = 2; i <= n; ++i) cin >> x, adj[i].push_back(x), adj[x].push_back(i);
    dfs(1); for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
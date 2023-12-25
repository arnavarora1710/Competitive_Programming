#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
const int maxn = 100005;
int n, m, u, v, it, indeg[maxn], ans[maxn]; 
vector<vector<int>> adj(maxn);

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        indeg[v]++; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (indeg[i] == 0) q.push(i);
    while (!q.empty()) {
        int node = q.front(); q.pop();
        ans[it++] = node;
        for (auto& neighbor : adj[node])
            if (--indeg[neighbor] == 0) q.push(neighbor);
    }
    if (it != n) cout << "IMPOSSIBLE";
    else for (int i = 0; i < n; ++i) cout << ans[i] << " ";
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
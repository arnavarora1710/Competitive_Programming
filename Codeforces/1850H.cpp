// https://codeforces.com/contest/1850/problem/H
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, m, x, y, d, ans[maxn];
bool vis[maxn];
set<pi> adj[maxn];

void dfs(int nn, int pp, int dd) {
    if (pp != -1) ans[nn] = dd + ans[pp];
    vis[nn] = true;
    for (auto cc : adj[nn])
        if (!vis[cc.f]) dfs(cc.f, nn, cc.s);
}

void solve() {
    cin >> n >> m;
    memset(ans, 0, maxn); memset(vis, 0, maxn);
    for (int i = 1; i <= n; ++i) adj[i].clear();
    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> d;
        adj[x].insert({y, d});
        adj[y].insert({x, -d});
    }
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) dfs(i, -1, 0);
    for (int i = 1; i <= n; ++i) {
        for (auto cc : adj[i]) {
            if (ans[i] != ans[cc.f] - cc.s) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
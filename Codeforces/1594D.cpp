// https://codeforces.com/contest/1594/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, m, u, v, mark[maxn];
bool contr, vis[maxn];
string s;
vector<pi> adj[maxn];

pi dfs(int nn) {
    int count = 1, imp = mark[nn];
    vis[nn] = true;
    for (auto cc : adj[nn]) {
        int team = (cc.s ? !mark[nn] : mark[nn]);
        if (!vis[cc.f]) {
            mark[cc.f] = team;
            pi ret = dfs(cc.f);
            count += ret.f;
            imp += ret.s;
        } else if (mark[cc.f] != team) {
            contr = true;
            return {0, 0};
        }
    }
    return {count, imp};
}

void solve() {
    cin >> n >> m;
    contr = false;
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        vis[i] = 0;
        mark[i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> s;
        int val = (s == "crewmate" ? 0 : 1);
        adj[u].push_back({v, val});
        adj[v].push_back({u, val});
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            pi ret = dfs(i);
            ans += max(ret.s, ret.f - ret.s);
        }
    }
    cout << (contr ? -1 : ans) << '\n';
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

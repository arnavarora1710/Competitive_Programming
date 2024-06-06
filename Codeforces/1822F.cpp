// https://codeforces.com/contest/1822/problem/F
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
int n, k, c, u, v, vis[maxn], dis[maxn];
vector<int> adj[maxn];

pi bfs(int nn) {
    for (int i = 1; i <= n; ++i)
        vis[i] = dis[i] = 0;
    queue<int> q; q.push(nn);
    vis[nn] = true;
    int mx = 0, idx = nn;
    while (!q.empty()) {
        int tp = q.front(); q.pop();
        for (int cc : adj[tp]) {
            if (!vis[cc]) {
                dis[cc] = dis[tp] + 1;
                if (dis[cc] > mx) {
                    mx = dis[cc];
                    idx = cc;
                }
                q.push(cc);
                vis[cc] = true;
            }
        }
    }
    return {mx, idx};
}

void solve() {
    cin >> n >> k >> c;
    for (int i = 1; i <= n; ++i) adj[i].clear();
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    pi pt1 = bfs(1);
    vector<int> saver(n + 1);
    for (int i = 1; i <= n; ++i) saver[i] = dis[i];
    bfs(pt1.s);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, k * dis[i] - c * saver[i]);
    cout << ans << '\n';
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

// https://codeforces.com/contest/1133/problem/F1
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
int n, m, deg[maxn];
bool vis[maxn];
vector<int> adj[maxn];
vector<pi> ans;

void bfs(int nn) {
    queue<int> q; q.push(nn);
    vis[nn] = true;
    while (!q.empty()) {
        int tp = q.front(); q.pop();
        for (auto cc : adj[tp]) {
            if (!vis[cc]) {
                vis[cc] = true;
                ans.push_back({tp, cc});
                q.push(cc);
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) deg[i] = adj[i].size();
    int mx = 0, idx = -1;
    for (int i = 1; i <= n; ++i) {
        if (mx < deg[i]) {
            mx = deg[i];
            idx = i;
        }
    }
    bfs(idx);
    for (auto pp : ans) cout << pp.f << " " << pp.s << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
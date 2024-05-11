// https://codeforces.com/contest/1760/problem/G
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
int n, a, b, u, v, w;
bool done, vis[maxn];
vector<pi> adj[maxn];
map<int, int> m;

void dfs(int nn, int pp, int xx, bool fl) {
    vis[nn] = true;
    if (fl && nn == b) return;
    if (!fl && nn != b && m[xx]) {
        done = 1;
        return;
    }
    if (fl) m[xx]++;
    for (auto cc : adj[nn])
        if (!vis[cc.f]) dfs(cc.f, nn, xx ^ cc.s, fl);
} 

void solve() {
    cin >> n >> a >> b; m.clear(); done = 0;
    for (int i = 1; i <= n; ++i) adj[i].clear();
    
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    memset(vis, 0, maxn);
    dfs(a, -1, 0, 1);
    memset(vis, 0, maxn);
    dfs(b, -1, 0, 0);
    if (done) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
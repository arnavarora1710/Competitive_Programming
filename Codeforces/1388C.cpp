// https://codeforces.com/problemset/problem/1388/C
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
int n, m, a[maxn], h[maxn], dp[maxn], bad[maxn];
bool ok;
vector<int> adj[maxn];

void dfs(int nn, int pp) {
    dp[nn] = a[nn];
    for (auto cc : adj[nn]) {
        if (cc != pp) {
            dfs(cc, nn);
            dp[nn] += dp[cc];
        }
    }
}

bool check(int k1, int k2) {
    if ((k1 + k2) % 2) return false;
    int x = (k1 + k2) / 2, y = (k1 - k2) / 2;
    return x >= 0 && y >= 0;
}

int dfs1(int nn, int pp) {
    int res = 0;
    for (auto cc : adj[nn]) {
        if (cc != pp) {
            res += dfs1(cc, nn);
        }
    }
    if (bad[nn] - a[nn] > res) ok = 0;
    return bad[nn];
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> h[i];
    for (int i = 1; i <= n; ++i) adj[i].clear();
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    for (int i = 1; i <= n; ++i) {
        if (!check(dp[i], h[i])) {
            cout << "NO\n";
            return;
        }
        bad[i] = (dp[i] - h[i]) / 2;
    }
    ok = 1;
    dfs1(1, -1);
    cout << (ok ? "YES\n" : "NO\n");
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

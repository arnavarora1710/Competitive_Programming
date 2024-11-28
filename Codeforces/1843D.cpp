// https://codeforces.com/contest/1843/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, q, x, y, dp[maxn];
vector<int> adj[maxn];

void dfs(int nn, int pp) {
    if (adj[nn].size() == 1 && adj[nn][0] == pp) {
        dp[nn] = 1;
        return;
    }
    for (auto& cc : adj[nn]) {
        if (cc != pp) {
            dfs(cc, nn);
            dp[nn] += dp[cc];
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        dp[i] = 0;
        adj[i].clear();
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    cin >> q;
    while (q--) {
        cin >> x >> y;
        cout << dp[x] * dp[y] << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

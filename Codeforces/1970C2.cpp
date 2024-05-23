// https://codeforces.com/contest/1970/problem/C2
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
int n, x, u, v;
vector<int> adj[maxn];

bool dfs(int nn, int pp, bool ron) {
    bool ok = !ron;
    for (auto& cc : adj[nn]) {
        if (cc != pp) {
            bool ret = dfs(cc, nn, !ron);
            if (ron && ret) return true;
            else if (!ron && !ret) return false;
        }
    }
    return ok;
}

void solve() {
    int trash;
    cin >> n >> trash;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> x;
    if (dfs(x, -1, 1)) cout << "Ron\n";
    else cout << "Hermione\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

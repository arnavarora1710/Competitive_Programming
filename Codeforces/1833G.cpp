// https://codeforces.com/contest/1833/problem/G
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
int n, u, v;
vector<int> adj[maxn];
map<pi, int> id;
vector<int> rem;

int dfs(int nn, int pp) {
    int sz = 1;
    for (int cc : adj[nn]) {
        if (cc != pp) {
            int ret = dfs(cc, nn);
            if (ret == -1) return -1;
            sz += ret;
        }
    }
    if (sz > 3) return -1;
    if (pp != -1 && sz == 3) {
        rem.push_back(id[{pp, nn}]);
        sz -= 3;
    }
    return sz;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) adj[i].clear();
    id.clear(); rem.clear();
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        id[{u, v}] = id[{v, u}] = i;
    }
    if (n % 3) {
        cout << -1 << '\n';
        return;
    }
    int ret = dfs(1, -1);
    if (ret == -1 || ret % 3) cout << -1 << '\n';
    else {
        cout << rem.size() << '\n';
        for (int i : rem) cout << i << ' ';
        cout << '\n';
    }
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

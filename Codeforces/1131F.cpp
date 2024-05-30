// https://codeforces.com/contest/1131/problem/F
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
int n, x, y;

class DisjointSet {
    vector<int> parent, size;
    public:
        DisjointSet (int n) {
            parent.resize(n + 1, 0);
            size.resize(n + 1, 0);
            for (int i = 0; i <= n; ++i) {
                    parent[i] = i; size[i] = 1;
            }
        }
        int findUPar(int node) {
            if (parent[node] == node) return node;
            return parent[node] = findUPar(parent[node]);
        }
        void unionBySize(int u, int v) {
            int ulp_u = findUPar(u), ulp_v = findUPar(v);
            if (ulp_u == ulp_v) return;
            if (size[ulp_u] < size[ulp_v]) {
                    parent[ulp_u] = ulp_v;
                    size[ulp_v] += size[ulp_u];
            }
            else {
                    parent[ulp_v] = ulp_u;
                    size[ulp_u] += size[ulp_v];
            }
        }
};

void solve() {
    cin >> n;
    vector<list<int>> adj(n + 1);
    for (int i = 1; i <= n; ++i)
        adj[i].push_back(i);
    DisjointSet dsu = *(new DisjointSet(n));
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        x = dsu.findUPar(x), y = dsu.findUPar(y);
        if (adj[x].size() >= adj[y].size()) adj[x].splice(adj[x].end(), adj[y]);
        else adj[y].splice(adj[y].end(), adj[x]);
        dsu.unionBySize(x, y);
        // for (int j = 1; j <= n; ++j) {
        //     cerr << j << ':';
        //     for (int k : adj[j]) cerr << k << ' ';
        //     cerr << '\n';
        // }
        // cerr << '\n';
    }
    for (int i = 1; i <= n; ++i) {
        if (adj[i].empty()) continue;
        for (int j : adj[i]) cout << j << ' ';
        break;
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

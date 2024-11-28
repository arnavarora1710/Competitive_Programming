// https://codeforces.com/contest/2019/problem/E
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template<class T> using omset = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define int long long
#define f first
#define s second
#define MULTI_TEST (1)

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

const int N = 200005, INF = 1e18, MOD = 1e9 + 7;
int n, k, q, x, y, u, v;
vii adj;
vi sz;
vi par;

int dfs(int nn, int pp) {
    sz[nn] = 1;
    par[nn] = pp;
    for (auto& cc : adj[nn])
        if (cc != pp)
            sz[nn] += dfs(cc, nn);
    return sz[nn];
}

int bfs() {
    // node, level
    queue<vi> q; q.push({1, 0});
    set<int> s = {sz[1]};
    vi vis(n + 1); vis[1] = 1;
    int ans = 0;
    map<int, pair<vi, int>> mp;
    vi deg(n + 1);
    mp[0] = {{1}, 0};
    int last = 0;
    while (!q.empty()) {
        auto v = q.front(); q.pop();
        int x = v[0], y = v[1];
        last = y;
        if (!mp.count(y)) {
            s.insert(ans + mp[y - 1].s);
            while (!mp[y - 1].f.empty()) {
                int it = mp[y - 1].f.back();
                while (it != 1 && deg[it] == 0) ans++, deg[par[it]]--, it = par[it];
                mp[y - 1].f.pop_back();
            }
        }
        if (x != 1 && adj[x].size() == 1) mp[y].f.push_back(x);
        for (auto& cc : adj[x]) {
            if (!vis[cc]) {
                deg[x]++, mp[y].s += sz[cc], vis[cc] = 1;
                q.push({cc, y + 1});
            }
        }
    }
    s.insert(ans + mp[last].s);
    return *s.begin();
}

void solve() {
    cin >> n;
    adj.clear(); adj.resize(n + 1); sz.resize(n + 1); par.resize(n + 1);
    for (int i = 0; i + 1 < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    cout << bfs() << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}
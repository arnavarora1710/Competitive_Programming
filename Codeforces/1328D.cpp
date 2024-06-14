// https://codeforces.com/contest/1328/problem/D
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
int n, a[maxn], vis[maxn];
vector<int> ans, adj[maxn];

void dfs(int nn) {
    vis[nn] = true;
    int x = (nn - 1 + n) % n;
    int y = (nn + 1) % n;
    int n1 = (a[x] != a[nn] ? ans[x] : 0);
    int n2 = (a[y] != a[nn] ? ans[y] : 0);
    int mn = inf;
    for (int i = 1; i <= 3; ++i) {
        if (i != n1 && i != n2) mn = min(mn, i);
    }
    ans[nn] = mn;
    for (auto cc : adj[nn]) {
        if (!vis[cc]) {
            dfs(cc);
        }
    }
}

void solve() {
    cin >> n; ans.clear(); ans.resize(n);
    for (int i = 0; i < n; ++i) adj[i].clear(), vis[i] = 0;
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> deg(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] != a[(i + 1) % n]) {
            deg[i]++, deg[(i + 1) % n]++;
            adj[i].push_back((i + 1) % n);
            adj[(i + 1) % n].push_back(i);
        }
    }
    bool ok = 0;
    for (int i = 0; i < n; ++i) {
        if (!vis[i] && deg[i] == 1) {
            dfs(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) dfs(i);
    }
    set<int> s(ans.begin(), ans.end());
    cout << s.size() << '\n';
    for (int i : ans) cout << i << ' ';
    cout << '\n';
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
const int maxn = 200005;
int n, a, b, vis[maxn]; vector<int> adj[maxn];

int dfs(int nn, int& dd) {
    vis[nn] = true;
    int m1 = 0, m2 = 0;
    for (auto& xx : adj[nn]) {
        if (!vis[xx]) {
            int ret = dfs(xx, dd);
            if (ret > m1) m2 = m1, m1 = ret;
            else if (ret > m2) m2 = ret;
        }
    }
    dd = max(dd, m1 + m2);
    return m1 + 1;
}


void solve() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 0;
    dfs(1, ans);
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
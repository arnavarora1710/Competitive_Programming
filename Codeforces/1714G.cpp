// https://codeforces.com/contest/1714/problem/G
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
int n, p, a, b, dp[maxn];
vector<vector<int>> adj[maxn];
vector<int> bs;

void dfs(int nn, int pp, int at) {
    for (auto cc : adj[nn]) {
        int child = cc[0], aa = cc[1], bb = cc[2];
        if (bs.empty()) bs.push_back(bb);
        else bs.push_back(bb + bs.back());
        int l = -1, r = bs.size();
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (bs[m] <= at + aa) l = m;
            else r = m;
        }
        dp[child] = l + 1;
        dfs(child, nn, aa + at);
        bs.pop_back();
    }
}

void solve() {
    cin >> n; 
    for (int i = 1; i <= n; ++i) adj[i].clear();
    for (int i = 2; i <= n; ++i) {
        cin >> p >> a >> b;
        adj[p].push_back({i, a, b});
    }
    memset(dp, 0, maxn);
    dfs(1, -1, 0);
    for (int i = 2; i <= n; ++i) cout << dp[i] << ' ';
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

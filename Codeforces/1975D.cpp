// https://codeforces.com/contest/1975/problem/D
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
int n, a, b, x, y, dp[maxn], dp1[maxn];
vector<int> adj[maxn];
vector<int> path;
bool flag;

void dfs(int nn, int pp) {
    if (nn == b) {
        flag = true;
        return;
    }
    for (int cc : adj[nn]) {
        if (cc != pp) {
            dfs(cc, nn);
            if (flag) {
                path.push_back(nn);
                return;
            }
        }
    }
}

void dfs1(int nn, int pp) {
    int ans = 1, mx = 0;
    for (int cc : adj[nn]) {
        if (cc != pp) {
            dfs1(cc, nn);
            mx = max(mx, dp1[cc]);
            ans += dp[cc];
        }
    }
    dp1[nn] = mx + 1;
    dp[nn] = ans;
}

void solve() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        dp[i] = 0;
        dp1[i] = 0;
    }
    path.clear();
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    flag = false;
    dfs(a, -1);
    reverse(path.begin(), path.end());
    int sz = path.size();
    int root = (sz == 0 ? a : path[sz / 2]);
    dfs1(root, -1);
    int res = sz / 2 + (n - 1) * 2 - (*(max_element(dp1 + 1, dp1 + n + 1)))+ (sz&1) + 1;
    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
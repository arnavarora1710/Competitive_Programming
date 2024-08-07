// https://codeforces.com/contest/461/problem/B
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (0)
const int maxn = 1e5 + 5, inf = 1e18, mod = 1e9 + 7;
int n, col[maxn], dp[maxn][2];
vector<int> adj[maxn];

void dfs(int nn, int pp) {
    dp[nn][0] = 1;
    dp[nn][1] = 0;
    for (auto& cc : adj[nn]) {
        if (cc != pp) {
            dfs(cc, nn);
            int n0 = dp[nn][0], n1 = dp[nn][1];
            int c0 = dp[cc][0], c1 = dp[cc][1];
            dp[nn][1] = (n1 * (c0 + c1) % mod + (n0 * c1) % mod) % mod;
            dp[nn][0] = (n0 * (c0 + c1) % mod) % mod;
        }
    }
    if (col[nn]) {
        dp[nn][1] = dp[nn][0];
        dp[nn][0] = 0;
    }
}

void solve() {
    cin >> n; 
    for (int i = 1; i < n; ++i) {
        int x; cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    for (int i = 0; i < n; ++i) cin >> col[i];
    dfs(0, -1);
    cout << dp[0][1];
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

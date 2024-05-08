// https://codeforces.com/contest/1946/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
int n, k, xx, yy, dp[100005];
vector<int> adj[100005];

int dfs(int nn, int pp, int x, int& ans) {
    int cnt = 1;
    for (int cc : adj[nn]) {
        if (cc != pp) {
            int val = dfs(cc, nn, x, ans);
            if (ans == k) cnt += val;
            else if (val >= x) ans++;
            else cnt += val;
        }
    }
    return dp[nn] = cnt;
}

bool check(int x) {
    int cnt = 0;
    memset(dp, 0, sizeof(dp));
    dfs(1, 0, x, cnt);
    return dp[1] >= x && cnt >= k;
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) adj[i].clear();
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n - 1; ++i) {
        cin >> xx >> yy;
        adj[xx].push_back(yy);
        adj[yy].push_back(xx);
    }
    int l = -1, r = n;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    cout << l << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
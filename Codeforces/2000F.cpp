// https://codeforces.com/contest/2000/problem/F
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
const int maxn = 1e3 + 5, inf = 1e18;
int n, k;
pi a[maxn];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i].f >> a[i].s;
    vector<vector<int>> cost(n);
    for (int i = 0; i < n; ++i) {
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({a[i].f, 0}); // row
        pq.push({a[i].s, 1}); // col
        int tot = 0;
        while (!pq.empty()) {
            pi tp = pq.top(); pq.pop();
            tot += tp.f;
            if (pq.size() >= 1) {
                pi tp1 = pq.top(); pq.pop();
                tp1.f = max(0LL, tp1.f - 1);
                pq.push(tp1);
            }
            if (tp.f) pq.push(tp);
            cost[i].push_back(tot);
        }
        cost[i].pop_back();
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, inf));
    for (int i = 0; i <= n; ++i) dp[i][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[i][j] = dp[i - 1][j];
            for (int l = 1; l <= k; ++l) {
                if (j >= l && l - 1 < cost[i - 1].size()) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - l] + cost[i - 1][l - 1]);
                } else break;
            }
        }
    }
    cout << (dp[n][k] == inf ? -1 : dp[n][k]) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

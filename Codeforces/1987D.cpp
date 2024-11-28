// https://codeforces.com/contest/1987/problem/D
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
const int maxn = 5e3 + 5, inf = 1e18;
int n, a[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) cnt[a[i]]++;
    set<int> s(a, a + n);
    vector<int> b(s.begin(), s.end());
    n = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dp[i][j] == -1) continue;
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
            if (j >= cnt[b[i]]) 
                dp[i + 1][j - cnt[b[i]]] = max(dp[i + 1][j - cnt[b[i]]], dp[i][j] + 1);
        }
    }
    int res = 0;
    for (int i = 0; i <= n; ++i)
        res = max(res, dp[n][i]);
    cout << n - res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

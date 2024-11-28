// https://codeforces.com/contest/1993/problem/D
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
const int maxn = 5e5 + 5, inf = 1e18;
int n, k, a[maxn];

bool check(int m, int need, int rem) {
    vector<int> dp(n, -inf);
    for (int i = 0; i < n; ++i) {
        int ok = a[i] >= m;
        int row = i / k, col = i % k;
        if (row) dp[i] = max(dp[i], dp[i - k]);
        if (!col) dp[i] = max(dp[i], ok);
        if (col && col < need) dp[i] = max(dp[i], ok + dp[i - 1]);
    }
    return dp.back() >= rem;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int need = n % k + (n % k == 0 ? k : 0);
    int rem = need / 2 + 1;
    int l = -1, r = 2e9;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (check(m, need, rem)) l = m;
        else r = m;
    }
    cout << l << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

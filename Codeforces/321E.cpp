// https://codeforces.com/contest/321/problem/E
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <iostream>
using namespace std;

#define int long long
#define MULTI_TEST (0)
const int maxn = 4005;
int n, k, a[maxn][maxn], dp[maxn][maxn];

int cost(int l, int r) {
    return (a[r][r] + a[l - 1][l - 1] - a[l - 1][r] - a[r][l - 1]);
}

void rec(int index, int l, int r, int ll, int rr) {
    if (ll > rr) return; 
    int mm = ll + (rr - ll) / 2, opt;
    dp[index][mm] = 1e13;
    for (int i = l; i <= min(r, mm); ++i) {
        if (dp[index][mm] > dp[index - 1][i - 1] + cost(i, mm)) {
            dp[index][mm] = dp[index - 1][i - 1] + cost(i, mm);
            opt = i;
        }
    }
    rec(index, l, opt, ll, mm - 1);
    rec(index, opt, r, mm + 1, rr);
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) { 
        for (int j = 1; j <= n; ++j) { 
            cin >> a[i][j];
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1]; 
        }
    }
    for (int i = 1; i <= n; ++i) dp[0][i] = 1e13;
    for (int i = 1; i <= k; ++i) {
        rec(i, 1, n, 1, n);
    }
    cout << dp[k][n] / 2;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

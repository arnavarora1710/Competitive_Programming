// https://codeforces.com/problemset/problem/1509/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;
typedef vector<vi> vii;
#define MULTI_TEST (0)

const int maxn = 2005;
int n, a[maxn];
vii dp(maxn, vi(maxn));

int memo(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (l == r) return 0;
    return dp[l][r] = a[r] - a[l] + min(memo(l + 1, r), memo(l, r - 1));
}

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i], fill(dp[i].begin(), dp[i].end(), -1);
    sort(a, a + n);
    cout << memo(0, n - 1);
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
// https://codeforces.com/problemset/problem/1764/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
int n, mod;

void solve() {
    cin >> n >> mod;

    vector<int> facts(n + 1, 1);
    vector<vector<int>> ncr(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) facts[i] = (facts[i - 1] * i) % mod;
    for (int i = 0; i <= n; ++i) ncr[i][0] = ncr[i][i] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; ++j) ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % mod;
    }

    int ans = 0;
    for (int i = 0; i < (n + 1) / 2; ++i) {
        int pick = n - i - 1;
        int lastPeg = (n / 2 + i) - ((n + 1) / 2) + 1;
        int optional = max(0LL, i - 1);
        for (int j = 0; j <= optional; ++j) {
            ans = (ans + ncr[optional][j] * facts[pick + j - 1] % mod * lastPeg) % mod;
        }
    }
    ans = (ans * n) % mod;
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
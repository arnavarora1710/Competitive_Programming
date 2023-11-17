#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, MAXN = 1e6 + 1;
long dp[MAXN], dp1[MAXN];

int main() {
    fill(dp, dp + MAXN, 0); fill(dp1, dp1 + MAXN, 0);
    dp[1] = 1, dp1[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        dp[i] = ((2 * dp[i - 1]) % MOD + dp1[i - 1]) % MOD;
        dp1[i] = ((4 * dp1[i - 1]) % MOD + dp[i - 1]) % MOD;
    }

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << (dp[n] + dp1[n]) % MOD << endl;
    }
    return 0;
}
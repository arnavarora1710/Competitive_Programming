// https://codeforces.com/problemset/problem/1513/C
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, MAXM = 200005;
int t, m; long dp[MAXM]; string n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i <= 8; ++i) dp[i] = 2;
    dp[9] = 3;
    for (int i = 10; i < MAXM; ++i) dp[i] = (dp[i - 9] + dp[i - 10]) % MOD;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        long ans = 0;
        for (int i = 0; i < n.size(); ++i) 
            ans = (ans + (n[i] - '0' + m >= 10 ? dp[n[i] - '0' - 10 + m] : 1)) % MOD;
        cout << ans << endl;
    }
    return 0;
}
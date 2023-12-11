// https://codeforces.com/problemset/problem/1513/C
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int t, m; string n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    vector<vector<vector<long>>> dp(200015, vector<vector<long>>(10, vector<long>(10)));
    // dp(i, j, k) : count of digit k after j is put through i operations
    for (int i = 0; i <= 9; ++i) dp[0][i][i] = 1;
    for (int i = 1; i < 200015; ++i) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= 8; ++k) dp[i][j][k + 1] = (dp[i][j][k + 1] + dp[i - 1][j][k]) % MOD;
            dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][9]) % MOD;
            dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j][9]) % MOD;
        }
    }
    while (t--) {
        cin >> n >> m; long ans = 0;
        for (int i = 0; i < n.size(); ++i)
            for (int j = 0; j <= 9; ++j) ans = (ans + dp[m][n[i] - '0'][j]) % MOD;
        cout << ans << endl;
    }
    return 0;
}
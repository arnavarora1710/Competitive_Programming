#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    int n; cin >> n; string a[n]; for (int i = 0; i < n; ++i) cin >> a[i];

    int dp[n][n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = 0;
                if (j - 1 >= 0 && a[i][j - 1] == '.') dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
                if (i - 1 >= 0 && a[i - 1][j] == '.') dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            } 
        }
    }

    cout << (a[n - 1][n - 1] == '.' ? dp[n - 1][n - 1] : 0);
    return 0;
}
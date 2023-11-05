#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    int n; cin >> n;
    // initialize dp:
    // dp(i): number of ways to construct i by dice throw(s)
    int dp[n + 1]; 
    
    // base case:
    // number of ways to construct 0 by dice throw(s)
    // is 1 which is just don't throw dice

    dp[0] = 1;

    // recurrence: dp(i) = sum from j = 1 to 6 of dp(i - j);
    // number of ways to construct i 
    // = number of ways to construct i - 1, i - 2, i - 3, i - 4, i - 5, i - 6
    // because we can get a dice throw with 1, 2, 3, 4, 5 or 6
    
    for (int i = 1; i <= n; ++i) {
        dp[i] = 0;
        for (int j = 1; j <= 6; ++j) {
            if (i - j >= 0) dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }
    cout << dp[n] % MOD;
    return 0;
}
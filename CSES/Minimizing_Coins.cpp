#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x; cin >> n >> x;
    int a[n]; for (int i = 0; i < n; ++i) cin >> a[i];

    // initialize dp:
    // dp(i): min number of coins used to make i
    long dp[x + 1]; 
    
    // base case:
    // min number of coins used to make 0 is 0
    dp[0] = 0;

    // recurrence: dp(i) = min over j of (1 + dp(i - a[j]))
    // min coins to make i
    // = min coins to make i - a[j] + 1
    // this is because we can make i by adding a coin to i - a[j]
    for (int i = 1; i <= x; ++i) {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; ++j) {
            if (i - a[j] >= 0) dp[i] = min(dp[i], 1 + dp[i - a[j]]);
        }
    }
    cout << (dp[x] == INT_MAX ? -1 : dp[x]);
    return 0;
}
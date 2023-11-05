#include <bits/stdc++.h>
using namespace std;

vector<int> digits(int n) {
    vector<int> digs;
    while (n) {
        digs.push_back(n % 10);
        n /= 10;
    }
    return digs;
}

int main() {
    int n; cin >> n;

    long dp[n + 1]; fill(dp, dp + n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        vector<int> digs = digits(i);
        dp[i] = INT_MAX;
        for (int j = 0; j <  (int) digs.size(); ++j) {
            if (i - digs[j] >= 0) dp[i] = min(dp[i], 1 + dp[i - digs[j]]);
        }
    }

    cout << dp[n];
    return 0;
}
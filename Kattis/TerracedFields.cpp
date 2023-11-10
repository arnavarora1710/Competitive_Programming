#include <bits/stdc++.h>
using namespace std;

int countDig(long long n) {
    int digs = 0;
    while (n) digs++, n /= 10;
    return digs;
}

int count6and8(long long n) {
    int ans = 0;
    while (n) {
        if (n % 10 == 6 || n % 10 == 8) ans++;
        n /= 10;
    }
    return ans;
}

int main() {
    int t; cin >> t;
    while (t--) {
        long long n; cin >> n;

        int digs = max(3, countDig(n)); vector<long long> num;

        long long tmp = n;
        for (int i = 0; i < max(3,digs); ++i) num.push_back(tmp % 10), tmp /= 10;
        reverse(num.begin(), num.end());

        long long dp[19][2];
        for (int i = 0; i < 19; ++i) memset(dp[i], 0, sizeof(long long) * 2);
        long long dp1[19][2];
        for (int i = 0; i < 19; ++i) memset(dp1[i], 0, sizeof(long long) * 2);

        dp[0][1] = 1;
        for (int i = 0; i < digs - 3; ++i) {
            for (int j = 0; j <= 9; ++j) {
                dp[i + 1][0] += dp[i][0];
                if (j == 6 || j == 8) dp1[i + 1][0] += dp1[i][0] + dp[i][0];
                else dp1[i + 1][0] += dp1[i][0];
            }
            for (int j = 0; j < num[i]; ++j) {
                dp[i + 1][0] += dp[i][1];
                if (j == 6 || j == 8) dp1[i + 1][0] += dp1[i][1] + dp[i][1];
                else dp1[i + 1][0] += dp1[i][1];
            }
            dp[i + 1][1] += dp[i][1];
            if (num[i] == 6 || num[i] == 8) dp1[i + 1][1] += dp1[i][1] + dp[i][1];
            else dp1[i + 1][1] += dp1[i][1];
        }
        
        int bound = num[digs - 3] * 100 + num[digs - 2] * 10 + num[digs - 1];
        long long ans = 0;
        for (int i = 0; i <= 999; ++i) {
            if (i > bound) {
                if (i % 8 == 0) 
                    ans += dp1[digs - 3][0] + count6and8(i) * dp[digs - 3][0];
            } else {
                if (i % 8 == 0) 
                    ans += (dp1[digs - 3][0] + dp1[digs - 3][1]) + 
                            count6and8(i) * (dp[digs - 3][0] + dp[digs - 3][1]);
            }  
        }
        if (n % 8) ans += count6and8(n);
        cout << ans << endl;
    }
}
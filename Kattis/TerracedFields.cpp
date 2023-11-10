#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vll;

// counts the number of sixes and eights in the number
int count6and8(ll n) {
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
        ll n; cin >> n;

        // make a digit array of the number
        vl num; ll tmp = n; int digs = 0;
        while (digs < 3 || tmp) num.push_back(tmp % 10), tmp /= 10, digs++;
        reverse(num.begin(), num.end());

        // dp - number of ways that we can make a prefix
        // dp1 - number of 6s and 8s till a prefix
        vll dp(19, vl(2)), dp1(19, vl(2));

        // base case - 
        // number of ways that we can make a 0 length prefix that is tight = 1
        // just take the first digit :)
        dp[0][1] = 1;
        // throw out the last three digits as those are the ones that
        // determine if a number is divisible by 8 or not
        for (int i = 0; i < digs - 3; ++i) {

            // go through all digits if not tight
            for (int j = 0; j <= 9; ++j) {
                dp[i + 1][0] += dp[i][0];
                if (j == 6 || j == 8) dp1[i + 1][0] += dp1[i][0] + dp[i][0];
                else dp1[i + 1][0] += dp1[i][0];
            }

            // go through all digits below current digit
            for (int j = 0; j < num[i]; ++j) {
                dp[i + 1][0] += dp[i][1];
                if (j == 6 || j == 8) dp1[i + 1][0] += dp1[i][1] + dp[i][1];
                else dp1[i + 1][0] += dp1[i][1];
            }

            // take the current digit
            dp[i + 1][1] += dp[i][1];
            if (num[i] == 6 || num[i] == 8) dp1[i + 1][1] += dp1[i][1] + dp[i][1];
            else dp1[i + 1][1] += dp1[i][1];
        }
        
        // determine bound for the last three digits
        int bound = num[digs - 3] * 100 + num[digs - 2] * 10 + num[digs - 1];
        ll ans = 0;

        // go through all 3 digit numbers
        for (int i = 0; i <= 999; ++i) {

            // if the number is greater than the bound, only add it to non-tight dp
            // otherwise, add it to both
            if (i > bound) {
                if (i % 8 == 0) 
                    ans += dp1[digs - 3][0] + count6and8(i) * dp[digs - 3][0];
            } else {
                if (i % 8 == 0) 
                    ans += (dp1[digs - 3][0] + dp1[digs - 3][1]) + 
                            count6and8(i) * (dp[digs - 3][0] + dp[digs - 3][1]);
            }  
        }

        // also, add in the nth step
        if (n % 8) ans += count6and8(n);
        cout << ans << endl;
    }
}
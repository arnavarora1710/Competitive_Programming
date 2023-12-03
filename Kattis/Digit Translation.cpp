#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6, MOD = 9302023;
string s; int dp[MAXN], dp1[MAXN];

int main() {
    cin >> s;
    vector<string> nums = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    // implemented prefix dp
    // dp : min length, dp1: count ways
    dp[0] = dp1[0] = 1;
    for (int i = 1; i < s.size(); ++i) {
        // init with i + 1 as that is the max a string of length i + 1 can be reduced to
        dp[i] = i + 1; int l = -1;

        for (auto& num : nums) {
            int len = num.size();
            string last(s.begin() + i - len + 1, s.begin() + i + 1);
            if (last == num) {
                // found a way to reduce the string
                dp[i] = (i - len >= 0 ? dp[i - len] : 0) + 1;
                l = len;
                break;
            }
        }

        // case work
        if (l == -1) {
            // if no way to reduce the string, just take the last smallest string
            // and add the current char to it
            dp[i] = dp[i - 1] + 1;
            dp1[i] = (dp1[i] + dp1[i - 1]) % MOD;
        }
        else {
            if (dp[i - 1] == (i - l >= 0 ? dp[i - l] : 0)) {
                // if both solutions are equivalent, add ways to 
                // get to the previous solutions
                dp1[i] = (dp1[i] + dp1[i - 1] + (i - l >= 0 ? dp1[i - l] : 1)) % MOD;
            } else if (dp[i - 1] < (i - l >= 0 ? dp[i - l] : 0)) {
                // if adding a char to the last smallest string is better,
                // then take that solution for both dp and dp1
                dp[i] = dp[i - 1] + 1;
                dp1[i] = (dp1[i] + dp1[i - 1]) % MOD;
            } else {
                // if reducing the string is better than add that to dp1
                // already added to dp on line 22
                dp1[i] = (dp1[i] + (i - l >= 0 ? dp1[i - l] : 1)) % MOD;
            }
        }
    }

    // final solution at the end of both dps
    cout << dp[s.size() - 1] << endl << dp1[s.size() - 1];
    return 0;
}
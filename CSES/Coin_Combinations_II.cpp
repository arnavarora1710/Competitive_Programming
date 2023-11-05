#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
 
int main()
{
    int n, x; cin >> n >> x;
    int a[n]; for (int i = 0; i < n; ++i) cin >> a[i];
 
    // basically subset sum
    // initialize dp:
    // dp(i): number of ordered ways to construct i using the given coins
    int dp[x + 1], prev[x + 1];
    fill(dp, dp + x + 1, 0); fill(prev, prev + x + 1, 0);

    // base case:
    // number of ordered ways to construct 0 is 1
    // just don't pick any coin
    dp[0] = 1; prev[0] = 1;

    // recurrence:
    // dp(i) = prev(i) + dp(j - a[i - 1]) if pick
    // dp(i) = prev(i) if not pick
    // unbounded knapsack with space optimization!
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= x; ++j) {
            if (j - a[i - 1] >= 0) {
                dp[j] = (prev[j] + dp[j - a[i - 1]]) % MOD;
            } else dp[j] = prev[j];
        }
        copy(dp, dp + x + 1, prev);
    }

    cout << dp[x];
    return 0;
}


/*
Alternate, shorter solution:
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
 
int main()
{
    int n, x; cin >> n >> x;
    int a[n]; for (int i = 0; i < n; ++i) cin >> a[i];
 
    # c_1 x_1 + c_2 x_2 + ... c_n x_n = x
    # known : c_1, c_2, ... c_n, x
 
    int dp[x + 1];
 
    fill(dp, dp + x + 1, 0);
    dp[0] = 1;
 
    # a[i] is used as the starting point of the inner loop. 
    # This is because if the current element 'a[i]' is greater than the current sum 'j', 
    # it cannot contribute to making the sum 'j'.
    # otherwise, recurrence is just unbounded knapsack

    for (int i = 0; i < n; ++i)
        for (int j = a[i]; j <= x; ++j) 
            dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
        
    cout << dp[x];
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
   int n, x; cin >> n >> x;
   int a[n]; for (int i = 0; i < n; ++i) cin >> a[i];

   // initialize dp:
   // dp(i): number of ways to construct i using the given coins
   int dp[x + 1]; 

   // base case:
   // number of ways to construct 0 is 1
   // just don't use any coin

   dp[0] = 1;

   // recurrence: dp(i) = sum over j of (dp(i - a[j]))
   // number of ways to construct i
   // = number of ways to construct i - a[j] for all j

   for (int i = 1; i <= x; ++i) {
      dp[i] = 0;
      for (int j = 0; j < n; ++j) {
         if (i - a[j] >= 0) dp[i] = (dp[i] + dp[i - a[j]]) % MOD;
      }
   }

   cout << dp[x];
   return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;

int main() {
    int a, b; cin >> a >> b; if (a > b) swap(a, b);

    // dp(i, j) : min moves to cut a rectangle of i x j into squares
    int dp[a + 1][b + 1]; memset(dp, INF, sizeof(int) * (a + 1) * (b + 1));
    for (int i = 1; i <= a; ++i) dp[i][1] = i - 1;
    for (int i = 1; i <= b; ++i) dp[1][i] = i - 1;

    for (int i = 2; i <= a; ++i) {
        dp[i][i] = 0;
        for (int j = 2; j <= b; ++j) {
            for (int k = 1; k < j; ++k) 
                dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k] + 1);
            for (int k = 1; k < i; ++k)
                dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
        }
    }
    cout << dp[a][b];
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1003;
const int MAX_K = 5003;
const int INF = 1e9 + 7;

int dp[MAX_N][MAX_K];
int a[MAX_N][MAX_N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                cin >> a[i][j];
            }
        }

        memset(dp, -INF, sizeof(dp));
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            int sum = 0;
            for (int j = i; j <= n; j++) {
                sum += a[i][j];
                for (int l = k; l >= 0; l--) {
                    dp[j][l] = max(dp[j][l], (l == 0 ? sum : dp[j - 1][l - 1] + sum));
                }
            }
        }

        for (int i = 0; i < k; i++) {
            cout << dp[n][i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
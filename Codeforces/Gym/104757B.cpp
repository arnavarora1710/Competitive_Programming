// https://codeforces.com/gym/104757/problem/B
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

const int MAXM = 1000, MAXN = 1000, MAXK = 100;
int m, n, k;
double s, dp[MAXM + MAXN + 1][MAXK + 1];
vector<double> x, x2;

double cost(int l, int r) {
    double N = (r - l + 1);
    double B = -2 * (x[r] - x[l - 1]);
    double C = (r - l + 1) * (s / 2) * (s / 2) + (x2[r] - x2[l - 1]);

    double X = (x[r] - x[l - 1]) / N;
    return N * X * X + B * X + C;
}

signed main() {
    cin >> m >> n >> k >> s;
    x.resize(m + n + 1, 0);
    x2.resize(m + n + 1, 0);
    for (int i = 1; i <= m + n; i++) cin >> x[i];
    sort(x.begin(), x.end());
    for (int i = 1; i <= m + n; i++) {
        x2[i] = x2[i - 1] + x[i] * x[i];
        x[i] += x[i - 1];
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m + n; i++) {
        dp[i][1] = cost(1, i);
        for (int j = 2; j <= k; j++) {
            dp[i][j] = cost(1, i);
            for (int p = i - 1; p >= 1; p--)
                dp[i][j] = min(dp[i][j], dp[p][j - 1] + cost(p + 1, i));
        }
    }
    cout << fixed << setprecision(9) << dp[m + n][k];
    return 0;
}
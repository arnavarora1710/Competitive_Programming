// https://codeforces.com/problemset/problem/351/A
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 4e3 + 5, inf = 1e18;
int n;
double a[maxn], dp[maxn][maxn / 2];

void solve() {
    cin >> n;
    for (int i = 0; i < 2 * n; ++i) cin >> a[i];
    for (int i = 0; i < 2 * n; ++i) a[i] -= floor(a[i]);
    for (int i = 0; i < maxn; ++i)
        for (int j = 0; j < maxn / 2; ++j) dp[i][j] = inf;
    dp[0][0] = a[0];
    dp[0][1] = a[0] - ceil(a[0]);
    for (int i = 1; i < 2 * n; ++i) {
        for (int j = 0; j <= n && j <= i + 1; ++j) {
            double c1 = dp[i - 1][j] + a[i], c2 = inf;
            if (j) c2 = dp[i - 1][j - 1] + a[i] - ceil(a[i]);
            if (abs(c1) <= abs(c2)) {
                dp[i][j] = c1;
            } else {
                dp[i][j] = c2;
            }
        }
    }
    cout << fixed << setprecision(3) << abs(dp[2 * n - 1][n]);
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

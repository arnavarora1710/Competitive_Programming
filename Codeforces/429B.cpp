// https://codeforces.com/contest/429/problem/B
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 1005, inf = 1e18;
int n, m, a[maxn][maxn], dp1[maxn][maxn], dp2[maxn][maxn], dp3[maxn][maxn], dp4[maxn][maxn];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) cin >> a[i][j];
    dp1[0][0] = a[0][0];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i || j) {
                int c1 = -1, c2 = -1;
                if (i) c1 = dp1[i - 1][j];
                if (j) c2 = dp1[i][j - 1];
                dp1[i][j] = max(c1, c2) + a[i][j];
            }
        }
    }
    dp2[n - 1][0] = a[n - 1][0];
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            if (i + 1 < n || j) {
                int c1 = -1, c2 = -1;
                if (i + 1 < n) c1 = dp2[i + 1][j];
                if (j) c2 = dp2[i][j - 1];
                dp2[i][j] = max(c1, c2) + a[i][j];
            }
        }
    }
    dp3[0][m - 1] = a[0][m - 1];
    for (int i = 0; i < n; ++i) {
        for (int j = m - 1; j >= 0; --j) {
            if (i || j + 1 < m) {
                int c1 = -1, c2 = -1;
                if (i) c1 = dp3[i - 1][j];
                if (j + 1 < m) c2 = dp3[i][j + 1];
                dp3[i][j] = max(c1, c2) + a[i][j];
            }
        }
    }
    dp4[n - 1][m - 1] = a[n - 1][m - 1];
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (i + 1 < n || j + 1 < m) {
                int c1 = -1, c2 = -1;
                if (i + 1 < n) c1 = dp4[i + 1][j];
                if (j + 1 < m) c2 = dp4[i][j + 1];
                dp4[i][j] = max(c1, c2) + a[i][j];
            }
        }
    }
    int ans = 0;
    for (int i = 1; i + 1 < n; ++i) {
        for (int j = 1; j + 1 < m; ++j) {
            int val = dp1[i][j - 1] + dp2[i + 1][j];
            int val1 = dp1[i - 1][j] + dp2[i][j - 1];
            int val2 = dp3[i][j + 1] + dp4[i + 1][j];
            int val3 = dp3[i - 1][j] + dp4[i][j + 1];
            ans = max(ans, max(val + val3, val1 + val2));
        }
    }
    cout << ans;
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}


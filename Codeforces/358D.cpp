// https://codeforces.com/problemset/problem/358/D
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 3e3 + 5, inf = 1e18;
int n, a[maxn], b[maxn], c[maxn], p[maxn], dp[maxn], M[maxn][maxn];

bool cmp(int i, int j) {
    return c[i] - b[i] > c[j] - b[j];
}

void init() {
    int i, j;
    for (i = 0; i < n; i++)
        M[i][i] = i;
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (cmp(M[i][j - 1], j))
                M[i][j] = M[i][j - 1];
            else
                M[i][j] = j;
}

int sum(int i, int j) {
    return p[j] - (i ? p[i - 1] : 0);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) cin >> c[i];
    init();
    for (int i = 0; i < n; ++i) p[i] = (i ? p[i - 1] : 0) + b[i];
    for (int i = 0; i < n; ++i) {
        dp[i] = a[i] + (i ? p[i - 1] : 0);
        for (int j = 0; j < i - 1; ++j) {
            int ret = M[j + 1][i - 1];
            dp[i] = max(dp[i], dp[j] + sum(j + 1, i - 1) + c[ret] - b[ret] + a[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans = max(ans, dp[i] + p[n - 1] - p[i]);
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

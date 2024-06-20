// https://codeforces.com/problemset/problem/1517/D
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 505, maxk = 15, inf = 1e13;
int n, m, h, dp[maxn][maxn][maxk];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

bool isValid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

void solve() {
    cin >> n >> m >> h;
    vector<vector<int>> right(n, vector<int>(m - 1)), down(n - 1, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j + 1 < m; ++j) cin >> right[i][j];
    for (int i = 0; i + 1 < n; ++i)
        for (int j = 0; j < m; ++j) cin >> down[i][j];
    if (h&1) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) cout << -1 << ' ';
            cout << '\n';
        }
        return;
    }
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j)
            for (int k = 1; k <= h / 2; ++k) dp[i][j][k] = inf; 
    for (int k = 1; k <= h / 2; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int l = 0; l < 4; ++l) {
                    int x = i + dx[l], y = j + dy[l];
                    if (isValid(x, y)) {
                        int cost;
                        if (l == 0) {
                            cost = down[x][y];
                        } else if (l == 1) {
                            cost = right[x][y];
                        } else if (l == 2) {
                            cost = down[i][j];
                        } else {
                            cost = right[i][j];
                        }
                        dp[i][j][k] = min(dp[i][j][k], dp[x][y][k - 1] + cost);
                    }
                } 
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cout << (dp[i][j][h / 2] << 1) << ' ';
        cout << endl;
    }
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

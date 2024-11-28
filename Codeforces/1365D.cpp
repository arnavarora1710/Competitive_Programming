// https://codeforces.com/contest/1365/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (1)
const int maxn = 55, inf = 1e10;
int n, m;
char a[maxn][maxn];
int d1[4] = {-1, 0, 1, 0};
int d2[4] = {0, -1, 0, 1};

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) cin >> a[i][j];
    vector<pi> indg, indb;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'G')
                indg.push_back({i, j});
            if (a[i][j] == 'B')
                indb.push_back({i, j});
        }
    }
    if (indg.empty()) {
        cout << "Yes\n";
    } else {
        for (auto& x : indb) {
            int i = x.f, j = x.s;
            for (int k = 0; k < 4; ++k) {
                int xx = d1[k], yy = d2[k];
                int dx = i + xx;
                int dy = j + yy;
                if (dx >= 0 && dx < n && dy >= 0 && dy < m) {
                    if (a[dx][dy] == 'G') {
                        cout << "No\n";
                        return;
                    } else if (a[dx][dy] != 'B') {
                        if (dx == n - 1 && dy == m - 1) {
                            cout << "No\n";
                            return;
                        }
                        a[dx][dy] = '#';
                    }
                }
            }
        }
        vector<vector<int>> dis(n, vector<int>(m, inf));
        vector<vector<bool>> vis(n, vector<bool>(m));
        vis[n - 1][m - 1] = true;
        dis[n - 1][m - 1] = 0;
        queue<pi> q; q.push({n - 1, m - 1});
        while (!q.empty()) {
            auto tp = q.front(); q.pop();
            int i = tp.f, j = tp.s;
            for (int k = 0; k < 4; ++k) {
                int xx = d1[k], yy = d2[k];
                int dx = i + xx;
                int dy = j + yy;
                if (dx >= 0 && dx < n && dy >= 0 && dy < m && !vis[dx][dy] && a[dx][dy] != '#') {
                    vis[dx][dy] = true;
                    dis[dx][dy] = dis[i][j] + 1;
                    q.push({dx, dy});
                }
            }
        }
        for (auto& x : indg) {
            int i = x.f, j = x.s;
            if (dis[i][j] >= inf) {
                cout << "No\n";
                return;
            }
        }
        cout << "Yes\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

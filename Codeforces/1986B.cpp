// https://codeforces.com/contest/1986/problem/B
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
const int maxn = 1e2 + 5, inf = 1e18;
int n, m, a[maxn][maxn];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

bool valid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> a[i][j];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int mx = 0;
            for (int k = 0; k < 4; ++k) {
                int x = dx[k] + i, y = dy[k] + j;
                if (valid(x, y)) {
                    mx = max(mx, a[x][y]);
                }
            }
            if (mx && mx <= a[i][j]) a[i][j] = mx;
            cout << a[i][j] << ' ';
        }
        cout << endl;
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

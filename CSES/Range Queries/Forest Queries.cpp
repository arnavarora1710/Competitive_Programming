#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
int n, q, a, b, c, d, grid[1005][1005], pr[1005][1005];
char ch;

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> ch;
            grid[i][j] = (ch == '.' ? 0 : 1);
        }
    }
    pr[0][0] = grid[0][0];
    for (int i = 1; i < n; ++i) {
        pr[0][i] = pr[0][i - 1] + grid[0][i];
        pr[i][0] = pr[i - 1][0] + grid[i][0];
    }
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < n; ++j)
            pr[i][j] = pr[i - 1][j] + pr[i][j - 1] - pr[i - 1][j - 1] + grid[i][j];
    while (q--) {
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        int down_left = (b ? pr[c][b - 1] : 0);
        int up_right = (a ? pr[a - 1][d] : 0);
        int intersection = (a && b ? pr[a - 1][b - 1] : 0);
        cout << pr[c][d] - down_left - up_right + intersection << endl;
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
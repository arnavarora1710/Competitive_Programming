// https://codeforces.com/contest/1695/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 1e3 + 5, inf = 1e18;
int n, m, a[maxn][maxn], mn[maxn][maxn], mx[maxn][maxn];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    if ((n + m) % 2 == 0) cout << "NO\n";
    else {
        mn[0][0] = mx[0][0] = a[0][0];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i || j) {
                    int c1 = (i ? mn[i - 1][j] : inf);
                    int c2 = (j ? mn[i][j - 1] : inf);
                    mn[i][j] = min(c1, c2) + a[i][j];
                    c1 = (i ? mx[i - 1][j] : -inf);
                    c2 = (j ? mx[i][j - 1] : -inf);
                    mx[i][j] = max(c1, c2) + a[i][j];
                }
            }
        }
        if (mn[n - 1][m - 1] > 0 || mx[n - 1][m - 1] < 0) cout << "NO\n";
        else cout << "YES\n";
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
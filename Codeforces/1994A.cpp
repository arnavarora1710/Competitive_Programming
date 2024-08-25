// https://codeforces.com/contest/1994/problem/A
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
const int maxn = 2e5 + 5, inf = 1e18;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) cin >> a[i][j];
    if (n == 1 && m == 1) cout << -1 << '\n';
    else if (m == 1) {
        cout << a[n - 1][0] << '\n';
        for (int i = 0; i + 1 < n; ++i) cout << a[i][0] << '\n';
    } else {
        for (int i = 0; i < n; ++i) {
            cout << a[i][m - 1] << ' ';
            for (int j = 0; j + 1 < m; ++j) cout << a[i][j] << ' ';
            cout << '\n';
        }
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

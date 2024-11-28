// https://codeforces.com/contest/1983/problem/B
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
const int maxn = 5e2 + 5, inf = 1e18;
int n, m, a[maxn][maxn], b[maxn][maxn];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char x; cin >> x;
            a[i][j] = x - '0';
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char x; cin >> x;
            b[i][j] = x - '0';
        }
    }
    for (int i = 0; i < n; ++i) {
        int tot1 = 0, tot2 = 0;
        for (int j = 0; j < m; ++j)
            tot1 += a[i][j], tot2 += b[i][j];
        if (tot1 % 3 != tot2 % 3) {
            cout << "NO\n";
            return;
        }
    }

    for (int i = 0; i < m; ++i) {
        int tot1 = 0, tot2 = 0;
        for (int j = 0; j < n; ++j)
            tot1 += a[j][i], tot2 += b[j][i];
        if (tot1 % 3 != tot2 % 3) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
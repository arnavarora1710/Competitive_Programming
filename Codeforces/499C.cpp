// https://codeforces.com/problemset/problem/499/C
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
const int maxn = 305, inf = 1e18;
int n, X1, Y1, X2, Y2, a[maxn][3];

void solve() {
    cin >> X1 >> Y1 >> X2 >> Y2 >> n;
    for (int i = 0; i < n; ++i) cin >> a[i][0] >> a[i][1] >> a[i][2];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int val1 = a[i][0] * X1 + a[i][1] * Y1 + a[i][2];
        int val2 = a[i][0] * X2 + a[i][1] * Y2 + a[i][2];
        if (val1 > 0 && val2 < 0) ans++;
        else if (val1 < 0 && val2 > 0) ans++;
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

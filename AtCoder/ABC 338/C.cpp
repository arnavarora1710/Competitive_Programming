#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
const int maxn = 15, INF = 1e18;
int n, x, y, a[maxn], b[maxn], c[maxn];

bool check(int xx, int yy) {
    for (int i = 0; i < n; ++i)
        if (xx * b[i] + yy * c[i] > a[i]) return false;
    return true;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i]; 
    for (int i = 0; i < n; ++i) cin >> c[i];
    int ans = 0;
    for (x = *max_element(a, a + n) + 1; x >= 0; --x) {
        if (!check(x, 0)) continue;
        y = INF;
        for (int i = 0; i < n; ++i)
            if (c[i]) y = min(y, (a[i] - x * b[i]) / c[i]);
        ans = max(ans, x + y);
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
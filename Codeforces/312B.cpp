// https://codeforces.com/problemset/problem/312/B
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define MULTI_TEST (0)
ld a, b, c, d;

void solve() {
    cin >> a >> b >> c >> d;
    ld p1 = a / b, p2 = c / d;
    ld p1p = 1 - p1, p2p = 1 - p2;
    ld ans = 0;
    for (int i = 1; i <= 1e5; i += 2) {
        ans += p1 * pow(p1p, (i - 1) / 2) * pow(p2p, (i - 1) / 2);
    }
    cout << fixed << setprecision(18) << ans;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
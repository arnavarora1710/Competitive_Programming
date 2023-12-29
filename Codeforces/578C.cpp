#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define lld long double
#define MULTI_TEST (0)
int n, a[200005];

lld f(lld m) {
    lld mx = 0, mx1 = 0, now = 0;
    for (int i = 0; i < n; ++i) {
        now += a[i] - m;
        if (now > mx) mx = now;
        if (now < 0) now = 0;
    }
    now = 0;
    for (int i = 0; i < n; ++i) {
        now += m - a[i];
        if (now > mx1) mx1 = now;
        if (now < 0) now = 0;
    }
    return max(mx, mx1);
}

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    lld l = -10001, r = 10001;
    while (r - l > 1e-13) {
        lld m1 = l + (r - l) / 3;
        lld m2 = r - (r - l) / 3;
        if (f(m1) > f(m2)) l = m1;
        else r = m2;
    }
    cout << fixed << setprecision(12) << f(l) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
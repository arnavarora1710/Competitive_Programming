#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define lld long double
#define MULTI_TEST (0)
int n, a[200005]; lld b[200005];

lld mcs() {
    lld mx = 0, now = 0;
    for (int i = 0; i < n; ++i) {
        now += b[i];
        if (now > mx) mx = now;
        if (now < 0) now = 0;
    }
    return mx;
}

void f(lld m, lld& c1, lld& c2) {
    for (int i = 0; i < n; ++i) b[i] = a[i] - m;
    c1 = mcs();
    for (int i = 0; i < n; ++i) b[i] *= -1;
    c2 = mcs();
}

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    lld l = *min_element(a, a + n) - 1, r = *max_element(a, a + n) + 1;
    while (r - l > 1e-13) {
        lld m = l + (r - l) / 2, c1, c2;
        f(m, c1, c2);
        if (c1 > c2) l = m;
        else r = m;
    }
    lld m = l + (r - l) / 2, c1, c2; f(m, c1, c2);
    cout << fixed << setprecision(12) << max(c1, c2) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
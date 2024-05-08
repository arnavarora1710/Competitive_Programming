// https://codeforces.com/contest/1929/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int a, k, x;

void solve() {
    cin >> k >> x >> a;
    bool ok = 1;
    int cur = a;
    for (int _ = 1; _ <= x; ++_) {
        int l = 0, r = cur + 1;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (cur + (k - 1) * m <= a) l = m;
            else r = m;
        }
        if (r > cur) ok = 0;
        cur -= r;
    }
    if (ok && cur * k <= a) cout << "NO\n";
    else if (ok) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

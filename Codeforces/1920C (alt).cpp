// https://m2.codeforces.com/contest/1920/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n, a[200005];

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    for (int factor = 1; factor <= n; ++factor) {
        if (n % factor == 0) {
            int g = 0;
            for (int i = 0; i + factor < n; ++i) 
                g = __gcd(g, abs(a[i] - a[i + factor]));
            ans += (g != 1);
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
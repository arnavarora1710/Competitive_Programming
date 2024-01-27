// https://codeforces.com/contest/1925/problem/B
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int x, n;

void solve() {
    cin >> x >> n;
    int ans = INT_MAX;
    for (int i = 1; i <= sqrt(x); ++i) {
        if (x % i == 0) {
            if (x / i == i) {
                if (i >= n) ans = min(ans, i);
            } else {
                if (i >= n) ans = min(ans, i);
                if (x / i >= n) ans = min(ans, x/i);
            }
        }
    }
    if (ans == INT_MAX) cout << 1 << endl;
    else cout << x / ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
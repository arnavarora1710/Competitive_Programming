// https://m2.codeforces.com/contest/1920/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n, a[200005];

bool fun(int incr, int mod) {
    bool flag = 1;
    for (int i = 0; i < incr; i++) {
        int odd = a[i] % mod;
        int tmp = odd;
        for (int j = i + incr; j < n; j += incr) {
            if (a[j] % mod != odd) {
                odd = -1; break;
            }
        }
        if (odd != tmp) {
            flag = 0; break;
        }
    }
    return flag;
}

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    vector<bool> vis(n + 1); int ans = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            int d1 = i, d2 = n / i;
            if (!vis[d1]) {
                vis[d1] = true;
                for (int k = 2; k <= 1000; ++k) {
                    if (fun(d1, k)) {
                        ans++; break;
                    }
                }
            }
            if (!vis[d2]) {
                vis[d2] = true;
                for (int k = 2; k <= 1000; ++k) {
                    if (fun(d2, k)) {
                        ans++; break;
                    }
                }
            }
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
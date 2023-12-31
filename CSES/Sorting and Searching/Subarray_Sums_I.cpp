#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
int n, k, a[200005];

void solve() {
    cin >> n >> k; for (int i = 0; i < n; ++i) cin >> a[i];
    int l, cur, ans; l = cur = ans = 0;
    for (int r = 0; r < n; ++r) {
        cur += a[r];
        if (cur == k) ans++;
        else {
            while (cur > k) cur -= a[l++];
            if (cur == k) ans++;
        }
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
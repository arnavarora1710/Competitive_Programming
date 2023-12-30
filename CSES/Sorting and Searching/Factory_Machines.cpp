#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
int n, k, a[200005];

bool check(int m) {
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        cur += m / a[i];
        if (cur >= k) return false;
    }
    return true;
}

void solve() {
    cin >> n >> k; for (int i = 0; i < n; ++i) cin >> a[i];
    int l = -1, r = 1e18 + 1;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    cout << r << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
// x1 + x2 + ... xn = k
// objective: min(max(p_i * x_i))
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
int n, a[200005];

int f(int m) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) cnt += abs(m - a[i]);
    return cnt;
}

void solve() {
    cin >> n; int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mn = min(mn, a[i]), mx = max(mx, a[i]);
    }
    int l = mn - 1, r = mx + 1;
    while (r - l > 2) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        if (f(m1) > f(m2)) l = m1;
        else r = m2;
    }
    cout << f(r - 1) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
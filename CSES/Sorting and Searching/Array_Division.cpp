#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
int n, k, a[200005];

bool check(int m) {
    int s = 0, bounds = k - 1; bool ok = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > m) return true;
        if (!bounds) ok = 1;
        if (ok) s += a[i];
        else {
            if (s + a[i] > m) s = a[i], bounds--;
            else s += a[i];
        }
    }
    return s > m;
}

void solve() {
    int s = 0;
    cin >> n >> k; for (int i = 0; i < n; ++i) cin >> a[i], s += a[i];
    int l = -1, r = s + 1;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    cout << r;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
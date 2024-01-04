#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
int n, x, a[200005];

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> x, a[x] = i;
    int ans = 1;
    for (int i = 2; i <= n; ++i) {
        if (a[i] < a[i - 1]) ans++;
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
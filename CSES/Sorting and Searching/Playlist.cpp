#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
int n, a[200005]; map<int, int> m;

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0, last = -1;
    for (int i = 0; i < n; ++i) {
        if (m.count(a[i])) last = max(last, m[a[i]]);
        ans = max(ans, i - last);
        m[a[i]] = i;
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
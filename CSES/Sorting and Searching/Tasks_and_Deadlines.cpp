#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
int n; pair<int, int> a[200005];

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
    sort(a, a + n); int tm = 0, ans = 0;
    for (int i = 0; i < n; ++i)
        tm += a[i].first, ans += a[i].second - tm;
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

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
int n; pair<int, int> a[200005];

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i].second >> a[i].first;
    sort(a, a + n); int ans = 1, p = a[0].first;
    for (int i = 1; i < n; ++i) if (a[i].second >= p) ans++, p = a[i].first;
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
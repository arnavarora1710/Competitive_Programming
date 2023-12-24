#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
int n, x, a[200005], vis[200005];

void solve() {
    cin >> n >> x; for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n); int i = 0, j = n - 1, ans = 0;
    while (i < j) {
        if (a[i] + a[j] <= x) ans++, vis[i] = vis[j] = 1, i++, j--;
        else --j;
    }
    for (int i = 0; i < n; ++i) ans += !vis[i];
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
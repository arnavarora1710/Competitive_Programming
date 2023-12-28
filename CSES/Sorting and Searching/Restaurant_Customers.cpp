#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
const int maxn = 200005;
int n, k, x, y; pair<int, int> a[2 * maxn];

void solve() {
    cin >> n; 
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        a[k++] = {x, 1}, a[k++] = {y, -1};
    }
    sort(a, a + k - 1); 
    int ans = 0, s = 0;
    for (int i = 0; i < k; ++i) s += a[i].second, ans = max(ans, s);
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
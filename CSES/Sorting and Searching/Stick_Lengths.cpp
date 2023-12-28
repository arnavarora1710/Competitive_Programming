#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define MULTI_TEST (0)
int n, ans, a[200005];
 
void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n); 
    int med = (n&1 ? a[n / 2] : (a[n / 2] + a[n / 2 - 1]) / 2);
    for (int i = 0; i < n; ++i) ans += abs(a[i] - med);
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
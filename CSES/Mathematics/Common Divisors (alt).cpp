#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
 
#define MULTI_TEST (0)
int n, a[200005], m[1000005];
 
void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        int j, x = a[i];
        for (j = 1; j * j < x; ++j) {
            if (x % j == 0) {
                m[j]++, m[x / j]++;
            }
        }
        if (j * j == x) m[j]++;
    }
    int ans = 0;
    for (int i = 1; i < 1000005; ++i) {
        if (m[i] >= 2) ans = i;
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
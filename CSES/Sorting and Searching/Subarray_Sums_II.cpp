#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
int n, k, a[200005];

void solve() {
    cin >> n >> k; for (int i = 0; i < n; ++i) cin >> a[i];
    int sum = 0, ans = 0; 
    map<int, int> m; m[0] = 1;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        ans += m[sum - k];
        m[sum]++;
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
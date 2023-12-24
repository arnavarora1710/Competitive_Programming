#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
int n;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int ans = i * i * ((i * i) - 1) / 2 - 4 * (i - 2) * (i - 1);
        cout << ans << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
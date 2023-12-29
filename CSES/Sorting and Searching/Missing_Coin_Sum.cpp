#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
int n, a[200005];

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n); int s = 0;
    for (int i = 0; i < n; ++i) {
        if (s + 1 < a[i]) break;
        s += a[i];
    }
    cout << s + 1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
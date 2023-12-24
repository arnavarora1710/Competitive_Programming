#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
const int maxn = 2e5;
int n, m, k, a[maxn], b[maxn];

void solve() {
    cin >> n >> m >> k; int ans = 0;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    sort(a, a + n); sort(b, b + m); 
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (abs(a[i] - b[j]) <= k) ans++, i++, j++;
        else {
            if (a[i] - b[j] > k) j++;
            else i++;
        }
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
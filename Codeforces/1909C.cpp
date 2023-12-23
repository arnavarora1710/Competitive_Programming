#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
const int maxn = 2e5;
int n, l[maxn], r[maxn], c[maxn];

void solve() {
    cin >> n; 
    for (int i = 0; i < n; ++i) cin >> l[i];
    for (int i = 0; i < n; ++i) cin >> r[i];
    for (int i = 0; i < n; ++i) cin >> c[i];
    int ans = 0;
    set<int> s(l, l + n); vector<int> a(n);
    sort(r, r + n); sort(c, c + n, greater<int>());
    for (int i = 0; i < n; ++i) {
        auto x = s.lower_bound(r[i]); x--;
        a[i] = r[i] - *x;
        s.erase(*x);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) ans += a[i] * c[i];
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
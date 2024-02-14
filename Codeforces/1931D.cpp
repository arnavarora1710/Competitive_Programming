// https://codeforces.com/contest/1931/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int maxn = 200005;
int n, x, y, a[maxn];

void solve() {
    cin >> n >> x >> y;
    for (int i = 0; i < n; ++i) cin >> a[i];
    map<pair<int, int>, int> m;
    for (int i = 0; i < n; ++i)
        m[{a[i] % y, a[i] % x}]++;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        m[{a[i] % y, a[i] % x}]--;
        ans += m[{a[i] % y, (x - (a[i] % x)) % x}];
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
}


// https://codeforces.com/contest/1845/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 3e5 + 5, inf = 1e18;
int n, a[maxn];

void solve() {
    cin >> n; for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) a[i] += a[i - 1];
    vector<int> suf(n + 1); suf[n] = a[n];
    for (int i = n - 1; i >= 0; --i)
        suf[i] = min(suf[i + 1], a[i]);
    int ans = 0, mx = -1;
    for (int i = 0; i <= n; ++i) {
        if (a[i] - suf[i] > mx) {
            mx = a[i] - suf[i];
            ans = a[i];
        }
    }
    cout << ans << '\n';
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

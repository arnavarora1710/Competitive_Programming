#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
int n, q, l, r, a[maxn];

void solve() {
    cin >> n >> q; for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> dif(n + 1);
    vector<pi> qs;
    while (q--) {
        cin >> l >> r;
        l--, r--;
        qs.push_back({l, r});
        dif[l]++, dif[r + 1]--;
    }
    for (int i = 1; i <= n; ++i) dif[i] += dif[i - 1];
    vector<pi> b(n);
    for (int i = 0; i < n; ++i) b[i] = {dif[i], i};
    sort(b.begin(), b.end());
    sort(a, a + n);
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        c[b[i].s] = a[i];
    }
    for (int i = 1; i < n; ++i) c[i] += c[i - 1];
    int ans = 0;
    for (int i = 0; i < qs.size(); ++i) {
        l = qs[i].f, r = qs[i].s;
        ans += c[r] - (l ? c[l - 1] : 0);
    }
    cout << ans;
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

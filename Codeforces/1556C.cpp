// https://codeforces.com/problemset/problem/1556/C
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 2e3 + 5, inf = 1e18;
int n, a[maxn], d[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        int val = (i ? d[i - 1] : 0);
        d[i] = val + (i&1 ? -a[i] : a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i += 2) {
        int mn = a[i];
        for (int j = i + 1; j < n; j += 2) {
            int diff = d[j] - (i ? d[i - 1] : 0);
            int val = mn - max(0LL, diff);
            val += (j != i + 1);
            ans += max(0LL, val);
            if (diff < 0) break;
            mn = min(mn, diff);
        }
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

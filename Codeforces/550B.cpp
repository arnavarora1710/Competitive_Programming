// https://codeforces.com/problemset/problem/550/B
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
int n, l, r, x, a[maxn];

void solve() {
    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    for (int i = 0; i < (1 << n); ++i) {
        if (__builtin_popcount(i) >= 2) {
            int sum = 0, mn = inf, mx = -inf;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j))
                    sum += a[j], mn = min(mn, a[j]), mx = max(mx, a[j]);
            }
            if (l <= sum && sum <= r && (mx - mn) >= x)
                ans++;
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
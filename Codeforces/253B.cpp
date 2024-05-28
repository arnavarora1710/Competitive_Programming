// https://codeforces.com/problemset/problem/253/B
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
int n, a[maxn];

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    int ans = inf;
    for (int i = 0; i < n; ++i) {
        int l = i, r = n;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (2 * a[i] >= a[m]) l = m;
            else r = m;
        }
        ans = min(ans, i + n - l - 1);
    }
    cout << ans;
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

// https://codeforces.com/contest/1935/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e3 + 5, inf = 1e18;
int n, k;
pi a[maxn];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i].s >> a[i].f;
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        multiset<int> s;
        int tot = 0;
        for (int j = i; j < n; ++j) {
            s.insert(a[j].s);
            tot += a[j].s;
            while (!s.empty() && tot + a[j].f - a[i].f > k) {
                int mx = *(s.rbegin());
                tot -= mx;
                s.extract(mx);
            }
            ans = max(ans, (int)s.size());
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

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (1)
const int maxn = 3e5 + 5, inf = 1e18;
int n, a[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    set<int> s(a, a + n);
    if (s.size() == 1) {
        cout << -1 << '\n';
        return;
    }
    vector<pi> b;
    for (int i = 0; i < n; ++i) {
        int j = i + 1, tot = 1;
        while (j < n && a[j] == a[i]) j++, tot++;
        b.push_back({a[i], tot});
        i = j - 1;
    }
    int sz = b.size();
    if (b.back().f != b[0].f) {
        cout << 0 << '\n';
        return;
    }
    for (int i = 0; i < sz; ++i) {
        if (b[i].f != b[0].f && b[i].s > 1) {
            cout << 0 << '\n';
            return;
        }
    }
    int ans = inf;
    for (int i = 0; i < sz; ++i) {
        if (b[i].f == b[0].f) ans = min(ans, b[i].s);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

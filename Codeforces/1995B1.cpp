// https://codeforces.com/contest/1995/problem/B1
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
const int maxn = 2e5 + 5, inf = 1e18;
int n, k, a[maxn];

// k1 * x <= k - k2 * (x + 1)

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) cnt[a[i]]++;
    vector<pi> b;
    for (auto& v : cnt) b.push_back(v);
    int ans = 0;
    for (int i = 0; i < b.size(); ++i) {
        for (int k2 = 0; k2 <= cnt[b[i].f + 1]; ++k2) {
            if (k < k2 * (b[i].f + 1)) break;
            int k1 = min(b[i].s, (k - k2 * (b[i].f + 1)) / b[i].f);
            ans = max(ans, b[i].f * k1 + (b[i].f + 1) * k2);
        }
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

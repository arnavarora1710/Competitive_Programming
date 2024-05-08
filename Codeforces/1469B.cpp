// https://codeforces.com/contest/1469/problem/B
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, m, a[maxn], b[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; ++i) cin >> b[i];
    vector<int> pra(n), prb(m);
    pra[0] = a[0];
    for (int i = 1; i < n; ++i) pra[i] = pra[i - 1] + a[i];
    prb[0] = b[0];
    for (int i = 1; i < m; ++i) prb[i] = prb[i - 1] + b[i];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, pra[i]);
        for (int j = 0; j < m; ++j) {
            ans = max(ans, pra[i] + prb[j]);
            ans = max(ans, prb[j]);
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

// https://codeforces.com/contest/1951/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 3e5 + 5, inf = 1e18;
int n, m, k, a[maxn], c[maxn], pr[maxn];
pi b[maxn];

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) b[i] = {a[i], i};
    sort(b, b + n); memset(c, 0, sizeof(c));
    for (int i = 0; i < n; ++i) {
        c[b[i].s] = min(m, k);
        k -= min(m, k);
    }
    pr[0] = c[0];
    for (int i = 1; i < n; ++i) pr[i] = pr[i - 1] + c[i];
    int ans = 0;
    for (int i = 0; i < n; ++i) ans += c[i] * a[i];
    for (int i = 1; i < n; ++i) ans += pr[i - 1] * c[i];
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
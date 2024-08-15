// https://codeforces.com/contest/2000/problem/E
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

void solve() {
    int n, m, k, w; cin >> n >> m >> k >> w;
    vector<int> a(w);
    for (int i = 0; i < w; ++i) cin >> a[i];
    vector<vector<int>> cnt(n, vector<int>(m));
    vector<int> tot;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // tl = {max(0LL, i - k + 1), max(0LL, j - k + 1)}
            // tr = {max(0LL, i - k + 1), min(m - k, j)}
            // bl = {min(n - k, i), max(0LL, j - k + 1)}
            // br = {min(n - k, i), min(m - k, j)}
            int d1 = min(m - k, j) - max(0LL, j - k + 1) + 1;
            int d2 = min(n - k, i) - max(0LL, i - k + 1) + 1;
            tot.push_back(d1 * d2);
        }
    }
    sort(tot.begin(), tot.end(), greater<int>());
    sort(a.begin(), a.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < w; ++i) {
        ans += a[i] * tot[i];
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

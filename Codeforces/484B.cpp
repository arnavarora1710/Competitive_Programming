// https://codeforces.com/problemset/problem/484/b
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, maxm = 1e7 + 5, inf = 1e18;
int n, a[maxn], vis[maxm];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    set<int> s(a, a + n);
    vector<int> b(s.begin(), s.end());
    reverse(b.begin(), b.end());
    n = b.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int p = b[i];
        for (int j = 2 * b[i]; p <= b[0]; j += b[i]) {
            if (!vis[j]) {
                int l = -1, r = n;
                while (r - l > 1) {
                    int m = l + (r - l) / 2;
                    if (b[m] <= j - 1) r = m;
                    else l = m;
                }
                if (r != n) {
                    int idx = r;
                    if (b[idx] <= j) {
                        ans = max(ans, (b[idx] - p) % b[i]);
                    }
                }
                vis[j] = true;
            }
            p = j;
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

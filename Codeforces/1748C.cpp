// https://codeforces.com/contest/1748/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, a[maxn];
map<int, int> m;

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    int zeros = 0;
    vector<int> ind;
    for (int i = 0; i < n; ++i) {
        if (!a[i]) {
            ind.push_back(i);
            zeros++;
        }
    }
    ind.push_back(n);
    for (int i = 1; i < n; ++i) a[i] += a[i - 1];
    int ans = 0;
    if (!zeros) {
        for (int i = 0; i < n; ++i)
            if (!a[i]) ans++;
    } else {
        for (int i = 0; i < ind[0]; ++i) 
            if (!a[i]) ans++;
        for (int i = 0; i + 1 < ind.size(); ++i) {
            int j = ind[i], cnt = 0;
            while (j < ind[i + 1]) {
                m[a[j]]++;
                cnt = max(cnt, m[a[j++]]);
            }
            j = ind[i];
            while (j < ind[i + 1]) m[a[j++]]--;
            ans += cnt;
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


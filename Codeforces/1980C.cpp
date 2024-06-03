// https://codeforces.com/contest/1980/problem/C
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
int n, m, a[maxn], b[maxn], c[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    cin >> m;
    for (int i = 0; i < m; ++i) cin >> c[i];
    map<int, int> need, have, done;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) need[b[i]]++;
        done[b[i]]++;
    }
    for (int i = 0; i < m; ++i) have[c[i]]++;
    for (auto v : need) {
        if (v.s > have[v.f]) {
            cout << "NO\n";
            return;
        }
    }
    if (done[c[m - 1]]) cout << "YES\n";
    else cout << "NO\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

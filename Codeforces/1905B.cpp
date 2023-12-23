// https://codeforces.com/contest/1905/problem/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 100005;
int t, n, u, v, ans, sz[maxn];

signed main() {
    cin >> t;
    while (t--) {
        cin >> n; memset(sz, 0, sizeof(sz));
        for (int i = 0; i < n - 1; ++i) cin >> u >> v, sz[u]++, sz[v]++;
        for (int i = 1; i <= n; ++i) if (sz[i] == 1) ans++;
        cout << (ans + 1) / 2 << endl; ans = 0;
    }
    return 0;
}
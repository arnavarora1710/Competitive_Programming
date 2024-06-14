// https://codeforces.com/contest/1552/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e2 + 5, inf = 1e18;
int n, k;
bool vis[maxn];

bool between(int x, int y, int z) {
    return (x < z && z < y);
}

bool intersects(pi x, pi y) {
    if (x.f > x.s) swap(x.f, x.s);
    if (between(x.f, x.s, y.f) && !between(x.f, x.s, y.s)) return true;
    else if (between(x.f, x.s, y.s) && !between(x.f, x.s, y.f)) return true;
    else return false;
}

void solve() {
    cin >> n >> k;
    vector<pi> a(k);
    for (int i = 0; i < k; ++i) cin >> a[i].f >> a[i].s;
    for (int i = 1; i <= 2 * n; ++i) vis[i] = 0;
    for (int i = 0; i < k; ++i) vis[a[i].f] = vis[a[i].s] = 1;
    vector<int> have;
    for (int i = 1; i <= 2 * n; ++i) {
        if (!vis[i]) have.push_back(i);
    }
    for (int i = 0, j = have.size() / 2; j < have.size(); i++, j++) {
        a.push_back({have[i], have[j]});
    }
    int ans = 0;
    for (int i = 0; i < a.size(); ++i) {
        for (int j = i + 1; j < a.size(); ++j) {
            ans += intersects(a[i], a[j]);
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

// https://codeforces.com/contest/339/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
int n, m, p, x, a[maxn], seg[4 * maxn];
map<int, int> pos;

void build(int v, int l, int r, bool ok) {
    if (l == r) { 
        seg[v] = a[l];
        pos[l] = v;
    } else {
        int mid = l + (r - l) / 2;
        build(v << 1, l, mid, !ok);
        build(v << 1 | 1, mid + 1, r, !ok);
        if (!ok) seg[v] = seg[v << 1] | seg[v << 1 | 1];
        else seg[v] = seg[v << 1] ^ seg[v << 1 | 1];
    }
}

void update(int v) {
    seg[v] = x;
    v /= 2;
    bool ok = 1;
    while (v) {
        if (ok) seg[v] = seg[v << 1] | seg[v << 1 | 1];
        else seg[v] = seg[v << 1] ^ seg[v << 1 | 1];
        v /= 2; ok = !ok;
    }
}

void solve() {
    cin >> n >> m;
    int old_n = n;
    n = (1 << n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    build(1, 0, n - 1, old_n % 2 == 0);
    for (int i = 0; i < m; ++i) {
        cin >> p >> x;
        update(pos[--p]);
        cout << seg[1] << '\n';
    }
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

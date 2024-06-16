// https://codeforces.com/problemset/problem/1549/D
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
int n, a[maxn], d[maxn], seg[4 * maxn];

int GCD(int x, int y) {
    if (y == 0) return x;
    return GCD(y, x%y);
}

void build(int v, int ll, int rr) {
    if (ll == rr) seg[v] = d[ll]; 
    else {
        int mm = ll + (rr - ll) / 2;
        build(2*v, ll, mm);
        build(2*v + 1, mm + 1, rr);
        seg[v] = GCD(seg[2*v], seg[2*v + 1]);
    }
}

int get(int v, int ll, int rr, int l, int r) {
    if (l > r) return 0;
    if (ll == l && rr == r) return seg[v];
    int mm = ll + (rr - ll) / 2;
    return GCD(get(2*v, ll, mm, l, min(mm, r)), get(2*v + 1, mm + 1, rr, max(mm + 1, l), r));
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    for (int i = 0; i < 5 * n; ++i) seg[i] = 0;
    for (int i = 1; i < n; ++i) d[i - 1] = abs(a[i] - a[i - 1]);
    n--;
    build(1, 0, n - 1);
    int l = 0, r = 0, ans = 0;
    while (r < n && l < n) {
        if (get(1, 0, n - 1, l, r) == 1) l++;
        ans = max(ans, r - l + 1);
        r++;
    }
    cout << ans + 1 << '\n';
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

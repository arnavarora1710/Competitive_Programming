// https://codeforces.com/problemset/problem/1611/F
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
int n, k, a[maxn], pr[maxn], seg[4*maxn];

void build(int v, int ll, int rr) {
    if (ll == rr) seg[v] = pr[ll];
    else {
        int mm = ll + (rr - ll) / 2;
        build(2*v, ll, mm);
        build(2*v + 1, mm + 1, rr);
        seg[v] = min(seg[2*v], seg[2*v + 1]);
    }
}

int mn(int v, int ll, int rr, int l, int r) {
    if (l > r) return INT_MAX;
    if (l == ll && r == rr) return seg[v];
    int mm = ll + (rr - ll) / 2;
    return min(mn(2*v, ll, mm, l, min(mm, r)), mn(2*v + 1, mm + 1, rr, max(mm + 1, l), r));
}

bool check(int i, int m) {
    // cerr << i << ' ' << m << ' ' << mn(1, 0, n - 1, i, m) - (i ? pr[i - 1] : 0) << '\n';
    return k + mn(1, 0, n - 1, i, m) - (i ? pr[i - 1] : 0) >= 0;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) pr[i] = (i ? pr[i - 1] : 0) + a[i];
    // for (int i = 0; i < n; ++i) cerr << pr[i] << ' ';
    // cerr << '\n';
    build(1, 0, n - 1);
    int ans = -1, left, right;
    for (int i = 0; i < n; ++i) {
        int l = i - 1, r = n;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (check(i, m)) l = m;
            else r = m;
        }
        if (l != i - 1) {
            if (ans < l - i + 1) {
                ans = l - i + 1;
                left = i;
                right = l;
            }
        }
    }
    // cerr << '\n';
    if (ans == -1) cout << -1 << '\n';
    else cout << left + 1 << ' ' << right + 1 << '\n';
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

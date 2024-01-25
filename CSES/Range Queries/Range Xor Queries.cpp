#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
const int maxn = 200005;
int n, q, q1, q2, a[maxn], seg[4*maxn];

void build(int v, int ll, int rr) {
    if (ll == rr) seg[v] = a[ll]; 
    else {
        int mm = ll + (rr - ll) / 2;
        build(2*v, ll, mm);
        build(2*v + 1, mm + 1, rr);
        seg[v] = seg[2*v] ^ seg[2*v + 1];
    }
}

int get(int v, int ll, int rr, int l, int r) {
    if (l > r) return 0;
    if (ll == l && rr == r) return seg[v];
    int mm = ll + (rr - ll) / 2;
    return get(2*v, ll, mm, l, min(mm, r)) ^ get(2*v + 1, mm + 1, rr, max(mm + 1, l), r);
}

void solve() {
    cin >> n >> q; for (int i = 0; i < n; ++i) cin >> a[i];
    build(1, 0, n - 1);
    for (int i = 0; i < q; ++i) {
        cin >> q1 >> q2;
        cout << get(1, 0, n - 1, q1 - 1, q2 - 1) << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
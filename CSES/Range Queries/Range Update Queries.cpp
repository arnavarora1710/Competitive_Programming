#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
const int maxn = 200005;
int n, q, type, q1, q2, q3, a[maxn], seg[4*maxn];

void build(int v, int ll, int rr) {
    if (ll == rr) seg[v] = a[ll];
    else {
        int mm = ll + (rr - ll) / 2;
        build(2*v, ll, mm);
        build(2*v + 1, mm + 1, rr);
        seg[v] = 0;
    }
}

void upd(int v, int ll, int rr, int l, int r, int x) {
    if (l > r) return;
    if (l == ll && r == rr) seg[v] += x;
    else {
        int mm = ll + (rr - ll) / 2;
        upd(2*v, ll, mm, l, min(mm, r), x);
        upd(2*v + 1, mm + 1, rr, max(mm + 1, l), r, x);
    }
}

int get(int v, int ll, int rr, int pos) {
    if (ll == rr) return seg[v];
    int mm = ll + (rr - ll) / 2;
    if (pos <= mm) return seg[v] + get(2*v, ll, mm, pos);
    else return seg[v] + get(2*v + 1, mm + 1, rr, pos);
}

void solve() {
    cin >> n >> q; for (int i = 0; i < n; ++i) cin >> a[i];
    build(1, 0, n - 1);
    for (int i = 0; i < q; ++i) {
        cin >> type >> q1;
        if (type == 1) {
            cin >> q2 >> q3;
            upd(1, 0, n - 1, q1 - 1, q2 - 1, q3);
        } else cout << get(1, 0, n - 1, q1 - 1) << endl;
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
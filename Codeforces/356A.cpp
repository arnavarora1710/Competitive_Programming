// https://codeforces.com/contest/356/problem/A
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define MULTI_TEST (0)
int n, m, le, re, x;
const int maxn = 300005;

struct seg {
    int tr[4*maxn];
    int sz = maxn;

    int query(int v, int ll, int rr, int pos) {
        if (ll > rr) return 0;
        else if (ll == rr) return tr[v];
        else {
            int mm = ll + (rr - ll) / 2;
            if (pos <= mm) {
                int rec = query(v<<1, ll, mm, pos);
                if (rec) return rec;
                else return tr[v];
            }
            else {
                int rec = query(v<<1|1, mm + 1, rr, pos);
                if (rec) return rec;
                else return tr[v];
            }
        }
    }

    int query(int pos) { return query(1, 0, sz - 1, pos); }

    void update(int v, int ll, int rr, int val, int l, int r) {
        if (tr[v]) return;
        if (l > r) return;
        else if (ll == l && rr == r) tr[v] = val + 1;
        else {
            int mm = ll + (rr - ll) / 2;
            update(v<<1, ll, mm, val, l, min(r, mm));
            update(v<<1|1, mm + 1, rr, val, max(l, mm + 1), r);
        } 
    }

    void update(int l, int r, int val) { update(1, 0, sz - 1, val, l, r); }
};

void solve() {
    cin >> n >> m;
    seg tree;
    for (int i = 0; i < m; ++i) {
        cin >> le >> re >> x; le--, re--, x--;
        tree.update(le, x - 1, x);
        tree.update(x + 1, re, x);
    }
    for (int i = 0; i < n; ++i) 
        cout << tree.query(i) << " ";
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
const int maxn = 100005;
int n, m, tp, q1, q2, a[maxn];

struct seg {
    vector<int> tr;

    seg(int sz) { tr.assign(4*sz+1,0); }

    void build (int v, int ll, int rr) {
        if (ll == rr) tr[v] = a[ll];
        else {
            int mm = ll + (rr - ll) / 2;
            build(v<<1, ll, mm);
            build(v<<1|1, mm + 1, rr);
            tr[v] = tr[v<<1] + tr[v<<1|1];
        }
    }

    int query(int v, int ll, int rr, int l, int r) {
        if (l > r) return 0;
        else if (l == ll && r == rr) return tr[v];
        else {
            int mm = ll + (rr - ll) / 2;
            return query(v<<1, ll, mm, l, min(r, mm)) + query(v<<1|1, mm + 1, rr, max(mm + 1, l), r);
        }
    }

    void update(int v, int ll, int rr, int val, int pos) {
        if (ll == rr) tr[v] = val;
        else {
            int mm = ll + (rr - ll) / 2;
            if (pos <= mm) update(v<<1, ll, mm, val, pos);
            else update(v<<1|1, mm + 1, rr, val, pos);
            tr[v] = tr[v<<1] + tr[v<<1|1];
        }
    }
};

void solve() {
    cin >> n >> m; for (int i = 0; i < n; ++i) cin >> a[i];
    seg tree = *(new seg(n));
    tree.build(1, 0, n - 1);
    for (int i = 0; i < m; ++i) {
        cin >> tp >> q1 >> q2;
        if (tp == 1) tree.update(1, 0, n - 1, q2, q1);
        else cout << tree.query(1, 0, n - 1, q1, q2 - 1) << endl;
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
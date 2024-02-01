#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
const int maxn = 100005;
int n, m, tp, q1, q2, a[maxn];

struct seg {
    vector<pair<int, int>> tr;

    seg(int sz) { tr.resize(4*sz+1); }

    void build(int v, int ll, int rr) {
        if (ll == rr) tr[v] = {a[ll], 1};
        else {
            int mm = ll + (rr - ll) / 2;
            build(v<<1, ll, mm);
            build(v<<1|1, mm + 1, rr);
            if (tr[v<<1].first == tr[v<<1|1].first) {
                tr[v].first = tr[v<<1].first;
                tr[v].second = tr[v<<1].second + tr[v<<1|1].second;
            }
            else if (tr[v<<1].first > tr[v<<1|1].first) tr[v] = tr[v<<1|1];
            else tr[v] = tr[v<<1];
        }
    }

    pair<int, int> query(int v, int ll, int rr, int l, int r) {
        if (l > r) return {INT_MAX, 0};
        else if (l == ll && r == rr) return tr[v];
        else {
            int mm = ll + (rr - ll) / 2;
            pair<int, int> left = query(v<<1, ll, mm, l, min(r, mm));
            pair<int, int> right = query(v<<1|1, mm + 1, rr, max(mm + 1, l), r);
            pair<int, int> res;
            if (left.first == right.first) {
                res.first = left.first;
                res.second = left.second + right.second;
            }
            else if (left.first > right.first) res = right;
            else res = left;
            return res;
        }
    }

    void update(int v, int ll, int rr, int val, int pos) {
        if (ll == rr) tr[v] = {val, 1};
        else {
            int mm = ll + (rr - ll) / 2;
            if (pos <= mm) update(v<<1, ll, mm, val, pos);
            else update(v<<1|1, mm + 1, rr, val, pos);
            if (tr[v<<1].first == tr[v<<1|1].first) {
                tr[v].first = tr[v<<1].first;
                tr[v].second = tr[v<<1].second + tr[v<<1|1].second;
            }
            else if (tr[v<<1].first > tr[v<<1|1].first) tr[v] = tr[v<<1|1];
            else tr[v] = tr[v<<1];
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
        else { 
            pair<int, int> ans = tree.query(1, 0, n - 1, q1, q2 - 1);
            cout << ans.first << " " << ans.second << endl;
        }
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
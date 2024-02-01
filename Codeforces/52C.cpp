// https://codeforces.com/problemset/problem/52/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
const int maxn = 200005;
int n, q, xx, a[maxn];
string query;

struct seg {
    vector<int> tr, lz;

    seg(int n) {
        tr.assign(4*n+1, 0);
        lz.assign(4*n+1, 0);
    }

    void push(int v) {
        lz[v<<1] += lz[v];
        lz[v<<1|1] += lz[v];
        tr[v] += lz[v];
        lz[v] = 0; 
    }

    void pull(int v) {
        tr[v] = min(tr[v<<1] + lz[v<<1], tr[v<<1|1] + lz[v<<1|1]);
    }

    int rmq(int v, int ll, int rr, int l, int r) {
        if (l > r) return INT_MAX;
        else if (l == ll && r == rr) return lz[v] + tr[v];
        else {
            int mm = ll + (rr - ll) / 2;
            if (lz[v]) push(v);
            int left = rmq(v<<1, ll, mm, l, min(mm, r));
            int right = rmq(v<<1|1, mm + 1, rr, max(mm + 1, l), r);
            pull(v);
            return min(left, right);
        }
    }

    void update(int v, int ll, int rr, int val, int l, int r) {
        if (l > r) return;
        else if (l == ll && r == rr) lz[v] += val;
        else {
            int mm = ll + (rr - ll) / 2;
            if (lz[v]) push(v);
            update(v<<1, ll, mm, val, l, min(mm, r));
            update(v<<1|1, mm + 1, rr, val, max(mm + 1, l), r);
            pull(v);
        }
    }
};

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    seg tree = *(new seg(n));
    for (int i = 0; i < n; ++i) tree.update(1, 0, n - 1, a[i], i, i);
    cin >> q; getline(cin, query);
    while (q--) {
        getline(cin, query); vector<int> qq;
        istringstream iss(query);
        int num;
        while (iss >> num) qq.push_back(num);
        if (qq.size() == 2) {
            if (qq[0] > qq[1]) {
                cout << min(tree.rmq(1, 0, n - 1, qq[0], n - 1), 
                            tree.rmq(1, 0, n - 1, 0, qq[1])) << endl;
            }
            else cout << tree.rmq(1, 0, n - 1, qq[0], qq[1]) << endl;
        } else {
            if (qq[0] > qq[1]) {
                tree.update(1, 0, n - 1, qq[2], qq[0], n - 1);
                tree.update(1, 0, n - 1, qq[2], 0, qq[1]);
            }
            else tree.update(1, 0, n - 1, qq[2], qq[0], qq[1]);
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
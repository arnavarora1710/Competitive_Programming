// https://codeforces.com/contest/1878/problem/E
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
const int maxn = 2e5 + 5;
int n, q, l1, k, a[maxn], seg[4 * maxn];

void build(int v, int ll, int rr) {
    if (ll == rr) seg[v] = a[ll]; 
    else {
        int mm = ll + (rr - ll) / 2;
        build(2*v, ll, mm);
        build(2*v + 1, mm + 1, rr);
        seg[v] = seg[2*v] & seg[2*v + 1];
    }
}

int get(int v, int ll, int rr, int l, int r) {
    if (l > r) return ~0;
    if (ll == l && rr == r) return seg[v];
    int mm = ll + (rr - ll) / 2;
    return get(2*v, ll, mm, l, min(mm, r)) & get(2*v + 1, mm + 1, rr, max(mm + 1, l), r);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    build(1, 0, n - 1);
    cin >> q;
    while (q--) {
        cin >> l1 >> k; l1--;
        int l = l1 - 1, r = n;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (get(1, 0, n - 1, l1, m) >= k)
                l = m;
            else 
                r = m;
        }
        if (get(1, 0, n - 1, l1, l) >= k)
            cout << l + 1 << " ";
        else 
            cout << -1 << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
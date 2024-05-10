// https://codeforces.com/contest/1791/problem/F
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, q, tp, l, r, x, a[maxn], seg[4 * maxn], p[maxn][20];

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
    for (int i = 0; i < 4 * maxn; ++i) seg[i] = 0;
    for (int i = 0; i < n; ++i) {
        int num = a[i];
        p[i][0] = num;
        for (int j = 1; j < 20; ++j) {
            int val = num, sum = 0;
            while (val) {
                sum += (val % 10);
                val /= 10;
            }
            p[i][j] = sum;
            num = sum;
        }
    }
    while (q--) {
        cin >> tp;
        if (tp == 1) {
            cin >> l >> r;
            upd(1, 0, n - 1, l - 1, r - 1, 1);
        } else {
            cin >> x;
            int val = get(1, 0, n - 1, x - 1);
            val = min(val, 19LL);
            cout << p[x - 1][val] << endl;
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
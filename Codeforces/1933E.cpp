// https://codeforces.com/contest/1933/problem/E
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
int n, q, l, u, a[maxn], pr[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    pr[0] = a[0];
    for (int i = 1; i < n; ++i) pr[i] = pr[i - 1] + a[i];
    cin >> q;
    while (q--) {
        cin >> l >> u; --l;
        int ll = l, rr = n;
        int val = (l ? pr[l - 1] : 0);
        while (rr - ll > 1) {
            int mm = ll + (rr - ll) / 2;
            if (pr[mm] - val <= u) ll = mm;
            else rr = mm;
        }
        if (ll == n - 1) cout << n << " ";
        else {
            int val1 = a[ll + 1];
            int val2 = pr[ll + 1] - val;
            val2 = val2 - u - 1;
            val1 -= val2 + 1;
            int neg = (val2 * (val2 + 1)) / 2;
            int pos = (val1 * (val1 + 1)) / 2;
            if (pos > neg)
                cout << ll + 2 << " ";
            else
                cout << ll + 1 << " ";
        }
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
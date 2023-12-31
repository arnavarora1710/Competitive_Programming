// https://codeforces.com/problemset/problem/279/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
const int maxn = 100005;
int n, q, q1, q2, a[maxn];

void solve() {
    cin >> n >> q; for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> ll(n), rr(n);
    iota(ll.begin(), ll.end(), 0);
    iota(rr.begin(), rr.end(), 0);
    ll[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] >= a[i]) ll[i] = ll[i - 1];
    }
    rr[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        if (a[i + 1] >= a[i]) rr[i] = rr[i + 1];
    }
    while (q--) {
        cin >> q1 >> q2; q1--, q2--;
        cout << (ll[q2] <= rr[q1] ? "Yes\n" : "No\n");
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
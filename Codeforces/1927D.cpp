// https://codeforces.com/contest/1927/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
const int maxn = 200005;
int n, q, l, r, a[maxn], m[maxn];

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        int j = i;
        while (j < n && a[i] == a[j])
            m[j++] = i - 1;
        i = j - 1;
    }
    cin >> q;
    while (q--) {
        cin >> l >> r;
        l--; r--;
        if (m[r] >= l) cout << m[r] + 1 << " " << r + 1 << endl;
        else cout << -1 << " " << -1 << endl;
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
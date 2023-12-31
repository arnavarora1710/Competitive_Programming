// https://codeforces.com/problemset/problem/368/B
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
const int maxn = 100005;
int n, q, x, a[maxn], suff[maxn]; map<int, int> m;

void solve() {
    cin >> n >> q; for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = n - 1; i >= 0; --i) {
        m[a[i]]++;
        suff[i] = m.size();
    }
    while (q--) {
        cin >> x;
        cout << suff[x - 1] << endl;
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
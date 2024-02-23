// https://codeforces.com/contest/1923/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
const int maxn = 3e5 + 5;
int n, q, l, r, a[maxn];

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) a[i] = (a[i] == 1 ? -1 : (a[i] - 1));
    for (int i = 1; i < n; ++i) a[i] += a[i - 1];
    while (q--) {
        cin >> l >> r;
        --l, --r;
        if (l == r) cout << "NO\n";
        else {
            int sum = a[r] - (l ? a[l - 1] : 0);
            cout << (sum >= 0 ? "YES\n" : "NO\n");
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
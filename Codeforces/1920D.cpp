// https://codeforces.com/contest/1920/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n, q, b, x, k;

void solve() {
    cin >> n >> q;
    int sz = 0; vector<pair<int, int>> a;
    for (int i = 0; i < n; ++i) {
        cin >> b >> x;
        if (b == 1) {
            sz++;
            a.push_back({x, sz});
        } else {
            sz *= (x + 1);
        }
    }
    for (int i = 0; i < q; ++i) cin >> k;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
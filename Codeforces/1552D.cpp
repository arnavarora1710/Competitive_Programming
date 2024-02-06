// https://codeforces.com/problemset/problem/1552/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define MULTI_TEST (1)
int n, a[15];
map<int, int> m;

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    m.clear();
    for (int i = 0; i < (1 << n); ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j)
            if (i & (1 << j)) sum += a[j];
        m[sum]++;
    }
    cout << (m.size() == (1 << n) ? "NO\n" : "YES\n");
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
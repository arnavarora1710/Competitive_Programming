// https://codeforces.com/contest/1933/problem/B
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
const int maxn = 1e5 + 5;
int n, a[maxn];

void solve() {
    cin >> n; 
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; a[i] %= 3;
    }
    int cur = 0;
    for (int i = 0; i < n; ++i) cur += a[i];
    cur %= 3;
    if (cur == 0) cout << 0 << endl;
    else if (cur == 1) {
        bool ok = 0;
        for (int i = 0; i < n; ++i)
            if (a[i] == 1) ok = 1;
        if (ok) cout << 1 << endl;
        else cout << 2 << endl;
    }
    else cout << 1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
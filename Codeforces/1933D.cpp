// https://codeforces.com/contest/1933/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
const int maxn = 1e5 + 5, inf = 1e18;
int n, a[maxn];

void solve() {
    cin >> n; 
    int cnt = 0, mn = inf;
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; mn = min(mn, a[i]);
    }
    for (int i = 0; i < n; ++i)
        if (mn == a[i]) cnt++;

    if (cnt == 1) cout << "YES\n";
    else {
        bool ok = 0;

        for (int i = 0; i < n; ++i) 
            if (a[i] % mn != 0) ok = 1;
        
        cout << (ok ? "YES\n" : "NO\n");
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
// https://codeforces.com/contest/1804/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, x, p; 

void submit(bool yes) {
    cout << (yes ? "YES\n" : "NO\n");
}

void solve() {
    cin >> n >> x >> p;
    for (int i = 1; i <= min(2 * n, p); ++i) {
        int val = (x + (i * (i + 1)) / 2) % n;
        if (!val) {
            submit(1);
            return;
        }
    }
    submit(0);
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
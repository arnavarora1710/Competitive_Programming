// https://codeforces.com/contest/1926/problem/E
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n, k;

void solve() {
    cin >> n >> k;
    for (int layer = 2; layer <= 2 * n; layer <<= 1) {
        int cnt = round(n / (double) layer); 
        if (k <= cnt) {
            cout << (layer>>1) * (2 * k - 1) << endl;
            return;
        }
        else k -= cnt;
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
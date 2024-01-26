#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define MULTI_TEST (0)
int n, x, a[1000005];

void solve() {
    cin >> n; 
    for (int i = 0; i < n; ++i) {
        cin >> x;
        a[x]++;
    }
    for (int i = 1000005; i; --i) {
        int ans = 0;
        for (int j = i; j < 1000005; j += i) ans += a[j];
        if (ans >= 2) {
            cout << i;
            break;
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
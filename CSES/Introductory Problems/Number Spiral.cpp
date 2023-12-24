#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int x, y;

void solve() {
    cin >> x >> y;
    if (x > y) cout << x*x - x + 1 + (x&1 ? y - x : x - y) << endl;
    else if (x < y) cout << y*y - y + 1 + (y&1 ? y - x : x - y) << endl;
    else cout << x*x - x + 1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

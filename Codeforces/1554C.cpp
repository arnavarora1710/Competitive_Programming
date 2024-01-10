// https://codeforces.com/problemset/problem/1554/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n, m;

void solve() {
    cin >> n >> m; ++m;
    int ans = 0;
    for (int i = 31; i >= 0; --i) {
        int bitm = (m>>i)&1;
        int bitn = (n>>i)&1;
        if (bitn && !bitm) break;
        if (!bitn && bitm) ans |= (1 << i);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
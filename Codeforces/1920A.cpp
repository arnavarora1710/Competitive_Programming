// https://m2.codeforces.com/contest/1920/problem/A
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n, a, x;

void solve() {
    cin >> n;
    int mx = 1e10, mn = 0;
    set<int> note;
    for (int i = 0; i < n; ++i) {
        cin >> a >> x;
        if (a == 1) mn = max(mn, x);
        else if (a == 2) mx = min(mx, x);
        else note.insert(x);
    }
    if (mn > mx) {
        cout << 0 << endl;
        return;
    }
    int ans = mx - mn + 1;
    for (int xx : note) {
        if (xx >= mn && xx <= mx) ans--;
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
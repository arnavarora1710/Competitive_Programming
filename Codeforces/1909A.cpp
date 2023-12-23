#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n, x, y;

void solve() {
    cin >> n; int one, two, three, four, dy, lx, uy, rx;
    one = two = three = four = dy = lx = uy = rx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        if (x > 0 && y > 0) one++;
        else if (x < 0 && y < 0) three++;
        else if (x < 0 && y > 0) two++;
        else if (x > 0 && y < 0) four++;
        else if (x > 0 && y == 0) rx++;
        else if (x < 0 && y == 0) lx++;
        else if (x == 0 && y > 0) uy++;
        else if (x == 0 && y < 0) dy++;
    }
    bool ans = (one > 0 && three > 0) || (two > 0 && four > 0) || (one > 0 && two > 0 && dy > 0)
    || (one > 0 && four > 0 && lx > 0) || (two > 0 && three > 0 && rx > 0) || 
    (three > 0 && four > 0 && uy > 0) || (one > 0 && lx > 0 && dy > 0)
    || (two > 0 && dy > 0 && rx > 0) || (three > 0 && uy > 0 && rx > 0)
    || (four > 0 && uy > 0 && lx > 0) || (rx > 0 && lx > 0 && uy > 0 && dy > 0); 
    if (ans) cout << "NO\n";
    else cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
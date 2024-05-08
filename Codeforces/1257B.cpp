// https://codeforces.com/contest/1257/problem/B
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int x, y;

void solve() {
    cin >> x >> y;
    if (x == 1) {
        if (y == 1) cout << "YES\n";
        else cout << "NO\n";
    } else if (x <= 3) {
        if (y <= 3) cout << "YES\n";
        else cout << "NO\n";
    } else cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

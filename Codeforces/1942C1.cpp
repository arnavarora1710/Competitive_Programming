// https://codeforces.com/contest/1942/problem/C1
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
int n, x, y, po[400005];

void solve() {
    cin >> n >> x >> y; 
    for (int i = 1; i <= x; ++i) cin >> po[i];
    sort(po + 1, po + x + 1);
    po[x + 1] = po[1] + n;
    int removed = n - x, ans = n - 2;
    for (int i = 1; i <= x; ++i) {
        int diff = po[i + 1] - po[i];
        ans -= (diff <= 2 ? 0 : diff - 1);
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
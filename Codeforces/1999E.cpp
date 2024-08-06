// https://codeforces.com/contest/1999/problem/E
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int l, r;

// 1 2 3
// 3 2 1
// 9 2 0
// 27 0 0
// 0 0 0

void solve() {
    cin >> l >> r;
    int ans = 0, cnt = 1, cur = 0;
    while (cnt <= l) cur++, cnt *= 3;
    int p = l; bool ok = 1;
    while (p <= r) {
        ans += cur * (min(r, cnt - 1) - p);
        if (ok) ans += cur * 2;
        else ans += cur;
        ok = 0;
        p = cnt;
        cnt *= 3, cur++;
    }
    cout << ans << '\n';
}
// 3 -> 2 => 2 = 2
// 9 -> 3, 4 => 2 + 2 = 4

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

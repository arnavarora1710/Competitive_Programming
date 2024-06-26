// https://codeforces.com/problemset/problem/1355/C
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
int a, b, c, d;

void solve() {
    cin >> a >> b >> c >> d;
    int ans = 0;
    for (int i = 0; i <= d - b; ++i) {
        int fin = max(b, c - i);
        int tot = min(c, d - i) - fin + 1;
        int fin1 = max(a, i + 1);
        int tot1 = (fin1 <= b ? b - fin1 + 1 : 0);
        ans += tot * tot1;
    }
    cout << ans;
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

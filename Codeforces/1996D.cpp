// https://codeforces.com/contest/1996/problem/D
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
int n, x;

// ab + ac + bc <= n
// 2ab + 2ac + 2bc <= 2n
// a + b + c <= x
// (a + b + c)^2 <= x^2
// a^2 + b^2 + c^2 + 2ab + 2ac + 2bc <= x^2

// a, b, c > 0
// fix a, b
// c <= x - a - b
// c <= (n - ab) / (a + b)

void solve() {
    cin >> n >> x;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int k = max(0LL, min(x - i - j, (n - i * j) / (i + j)));
            if (!k) break;
            ans += k;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

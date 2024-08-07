// https://codeforces.com/contest/478/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (0)
const int maxn = 5e5 + 5, inf = 1e18, mod = 1e9 + 7;
int R, G, h, ans, dp[maxn];

void solve() {
    cin >> R >> G;
    dp[0] = h = 1;
    for (; h * h + h <= 2 * (R + G); ++h)
        for (int j = R + G; j >= h; --j)
            dp[j] = (dp[j] + dp[j - h]) % mod;
    --h; 
    int sum = (h * h + h) >> 1;
    for (int i = 0; i <= R; ++i)
        if (sum - i <= G) ans = (ans + dp[i]) % mod;
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

// https://codeforces.com/contest/1994/problem/C
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
int n, k, a[maxn];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<int> dp(n + 2), p(n + 1);
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];
    for (int i = n; i >= 1; --i) {
        int l = i - 1, r = n + 1;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (p[m] - p[i - 1] <= k) l = m;
            else r = m;
        }
        dp[i] = (r <= n ? dp[r + 1] + 1 : 0) ;
    }
    int ans = n * (n + 1) / 2;
    for (int i = 1; i <= n; ++i) ans -= dp[i];
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

// https://codeforces.com/contest/455/problem/A
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
int n, a[maxn], dp[maxn];
map<int, int> cnt;

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    int mx = 0;
    for (int i = 0; i < n; ++i) cnt[a[i]]++, mx = max(mx, a[i]);
    for (auto& v : cnt) v.s *= v.f;
    int ans = 0;
    for (int i = 1; i <= mx; ++i) {
        dp[i] = max(dp[i - 1], (i > 1 ? dp[i - 2] : 0) + cnt[i]);
        ans = max(ans, dp[i]);
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
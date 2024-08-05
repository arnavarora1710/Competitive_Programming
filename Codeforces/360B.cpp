// https://codeforces.com/contest/360/problem/B
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
const int maxn = 2e3 + 5, inf = 1e18;
int n, k, a[maxn];

bool check(int m) {
    vector<int> dp(n, 1);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (abs(a[i] - a[j]) <= (i - j) * m) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    ans = n - ans;
    return ans <= k;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int l = -1, r = inf;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (check(m)) r = m;
        else l = m;
    }
    cout << r;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

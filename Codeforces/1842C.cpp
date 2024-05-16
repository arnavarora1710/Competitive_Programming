// https://codeforces.com/contest/1842/problem/C
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
int n, a[maxn], dp[maxn];
map<int, int> m;

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    m.clear();
    for (int i = 0; i < n; ++i) {
        if (!m.count(a[i])) {
            dp[i] = (i ? dp[i - 1] : 0);
        } else {
            dp[i] = max(dp[i - 1], m[a[i]] + i + 1);
        }
        int val = (i ? dp[i - 1] : 0) - i;
        if (!m.count(a[i]) || m[a[i]] < val)
            m[a[i]] = val;
    }
    cout << *(max_element(dp, dp + n)) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
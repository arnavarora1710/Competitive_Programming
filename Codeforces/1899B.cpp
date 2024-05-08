// https://codeforces.com/contest/1899/problem/B
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
int n, a[200005], pr[200005];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    pr[1] = a[1];
    for (int i = 2; i <= n; ++i) 
        pr[i] = pr[i - 1] + a[i];
    set<int> factors;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            factors.insert(i);
            factors.insert(n / i);
        }
    }
    int ans = 0;
    for (auto factor : factors) {
        int mn = LLONG_MAX, mx = LLONG_MIN;
        for (int i = factor; i <= n; i += factor) {
            int sum = pr[i] - pr[i - factor];
            mn = min(mn, sum);
            mx = max(mx, sum);
        }
        ans = max(ans, mx - mn);
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
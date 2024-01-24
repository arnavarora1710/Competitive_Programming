// https://m2.codeforces.com/contest/1920/problem/B
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n, k, x;

void solve() {
    cin >> n >> k >> x; 
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    vector<int> b(n);
    for (int i = 0; i < n; ++i) b[i] = a[i] * -1;
    vector<int> suffa(n), suffb(n);
    suffa[n - 1] = a[n - 1]; suffb[n - 1] = b[n - 1];
    for (int i = n - 2; i >= 0; --i) suffa[i] = suffa[i + 1] + a[i], suffb[i] = suffb[i + 1] + b[i];
    int ans = (k == n ? 0 : LLONG_MIN);
    for (int i = 0; i <= min(n - 1, k); ++i) {
        int suffix_index = i + x;
        ans = max(ans, suffb[i] + (suffix_index < n ? 2 * suffa[suffix_index] : 0));
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
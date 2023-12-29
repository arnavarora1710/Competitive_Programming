// https://codeforces.com/problemset/problem/1904/B
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
const int maxn = 100005;
int n, pr[maxn], ans[maxn]; vector<pair<int, int>> a(maxn);

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i].first, a[i].second = i;
    sort(a.begin(), a.begin() + n); pr[0] = a[0].first;
    for (int i = 1; i < n; ++i) pr[i] = pr[i - 1] + a[i].first;
    int k = n;
    for (int i = n - 1; i >= 0; --i) {
        ans[a[i].second] = k;
        if (a[i].first > pr[i - 1]) k = i;
    }
    for (int i = 0; i < n; ++i) cout << ans[i] - 1 << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
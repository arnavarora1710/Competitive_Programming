// https://codeforces.com/problemset/problem/1772/D
#pragma GCC optimization("unroll-loops")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, a[maxn];

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    int mn = 0, mx = inf;
    for (int i = 0; i + 1 < n; ++i) {
        int ml = (a[i] + a[i + 1]) / 2;
        int mr = (a[i] + a[i + 1] + 1) / 2;
        if (a[i] < a[i + 1]) mx = min(mx, ml);
        if (a[i] > a[i + 1]) mn = max(mn, mr);
    }
    if (mn <= mx) cout << mn << endl;
    else cout << -1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
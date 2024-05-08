// https://codeforces.com/contest/1934/problem/A
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n, a[105];
void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    int i = 0, j = n - 2, k = 1, l = n - 1;
    cout << abs(a[i] - a[j]) + abs(a[j] - a[k])
            + abs(a[k] - a[l]) + abs(a[l] - a[i]) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
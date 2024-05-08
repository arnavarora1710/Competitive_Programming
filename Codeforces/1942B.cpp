// https://codeforces.com/contest/1942/problem/B
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
int n, a[200005], b[200005];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    b[n - 1] = n - a[n - 1];
    int mn = b[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        b[i] = mn - a[i];
        mn = min(mn, b[i]);
    }
    for (int i = 0; i < n; ++i) cout << b[i] << " ";
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
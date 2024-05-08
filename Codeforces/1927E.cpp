// https://codeforces.com/contest/1927/problem/E
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n, k, a[200005];

void solve() {
    cin >> n >> k;
    int val = 1, idx = k - 2;
    while (idx != -2) {
        for (int i = idx; i < n; i += k)
            a[i] = val++; 
        idx -= 2; 
    }
    val = n, idx = k - 1;
    while (idx != -1) {
        for (int i = idx; i < n; i += k)
            a[i] = val--;
        idx -= 2;
    }
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
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

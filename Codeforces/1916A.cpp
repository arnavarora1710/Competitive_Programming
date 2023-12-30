// https://codeforces.com/contest/1916/problem/A
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n, k, x;

void solve() {
    cin >> n >> k; int prod = 1;
    for (int i = 0; i < n; ++i) cin >> x, prod *= x;
    if (2023 % prod) cout << "NO\n";
    else {
        cout << "YES\n";
        cout << 2023 / prod << " ";
        for (int i = 0; i < k - 1; ++i) cout << "1 ";
        cout << endl;
    } 
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
// https://codeforces.com/contest/1935/problem/A
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n; string a;

void solve() {
    cin >> n >> a;
    string b = a;
    reverse(b.begin(), b.end());
    if (b < a) {
        --n;
        if (n&1) cout << b << a << endl;
        else cout << b << endl;
    } else cout << a << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
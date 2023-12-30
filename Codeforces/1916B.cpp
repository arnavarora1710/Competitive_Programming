// https://codeforces.com/contest/1916/problem/B
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int a, b;

void solve() {
    cin >> a >> b;
    int g = gcd(a, b);
    if (a / g == 1) cout << b * b / a << endl;
    else cout << a * b / g << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
// https://codeforces.com/contest/1933/problem/A
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n, x;

void solve() {
    cin >> n; int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        sum += abs(x);
    }    
    cout << sum << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
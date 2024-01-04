// https://codeforces.com/problemset/problem/1514/A
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n, x;

void solve() {
    cin >> n; bool ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (ceil(sqrtf(x)) != sqrt(x)) ans = 1;
    }
    cout << (ans ? "YES\n" : "NO\n");
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
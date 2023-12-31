// https://codeforces.com/problemset/problem/373/A
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
int n; char x; map<char, int> m;

void solve() {
    cin >> n;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> x;
            if (x != '.') m[x]++;
        }
    }
    for (auto& xx : m) {
        if ((xx.second + 1) / 2 > n) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
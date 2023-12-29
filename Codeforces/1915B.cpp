// https://codeforces.com/problemset/problem/1915/B
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
char a[3][3];

void solve() {
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) cin >> a[i][j];
    set<char> s; s.insert('A'), s.insert('B'), s.insert('C');
    for (int i = 0; i < 3; ++i) 
        for (int j = 0; j < 3; ++j)
            if (a[i][j] == '?') {
                for (int k = 0; k < 3; ++k) if (k != i) s.erase(a[k][j]);
                cout << *s.rbegin() << endl;
                return;
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
// https://codeforces.com/contest/1925/problem/A
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n, k;

void solve() {
    cin >> n >> k;
    string a;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            a.push_back(j + 'a');
        }
    }
    cout << a << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
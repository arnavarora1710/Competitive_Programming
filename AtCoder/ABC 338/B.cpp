#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define MULTI_TEST (0)
string a;

void solve() {
    cin >> a; map<char, int> m;
    for (int i = 0; i < a.size(); ++i) m[a[i]]++;
    int mx = 0; char ch;
    for (auto& v : m) {
        if (v.second > mx) {
            mx = v.second;
            ch = v.first;
        }
    }
    cout << ch;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

string a;

void solve() {
    cin >> a;
    if (a[0] >= 'A' && a[0] <= 'Z') {
        bool ok = 1;
        for (int i = 1; i < a.size(); ++i) {
            if (a[i] < 'a' || a[i] > 'z') ok = 0;
        }
        if (ok) cout << "Yes";
        else cout << "No";
    } else cout << "No";
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
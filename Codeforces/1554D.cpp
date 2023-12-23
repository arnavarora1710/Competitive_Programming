// https://codeforces.com/problemset/problem/1554/D
#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n;

signed main() {
    cin >> t;
    while (t--) {
        cin >> n;
        if (n == 1) cout << "a" << endl;
        else {
            for (int i = 0; i < n / 2; ++i) cout << "a";
            cout << (n&1 ? "bc" : "b");
            for (int i = 0; i < n / 2 - 1; ++i) cout << "a";
            cout << endl;
        }
    }
    return 0;
}

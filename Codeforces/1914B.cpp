// https://codeforces.com/contest/1914/problem/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, k;

signed main() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = n; i >= k + 2; --i) cout << i << " ";
        for (int i = 1; i <= k + 1; ++i) cout << i << " ";
        cout << endl;
    }
    return 0;
}

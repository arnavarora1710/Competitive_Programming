// https://codeforces.com/contest/1901/problem/A
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50;
int t, n, x, a[MAXN];

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> x; for (int i = 0; i < n; ++i) cin >> a[i];
        int ans = max(a[0], (x - a[n - 1]) * 2);
        for (int i = 0; i < n - 1; ++i) ans = max(ans, a[i + 1] - a[i]);
        cout << ans << endl;
    }
    return 0;
}
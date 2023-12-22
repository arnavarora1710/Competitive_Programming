// https://codeforces.com/problemset/problem/1891/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, s, a[200005];

signed main() {
    cin >> t;
    while (t--) {
        cin >> n; for (int i = 0; i < n; ++i) cin >> a[i], s += a[i];
        sort(a, a + n); int ans = 0, tmp = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (tmp >= s-(s+1)/2) break;
            tmp += a[i]; ans++;
        }
        cout << (s+1)/2 + ans << endl; s = 0;
    }
    return 0;
}
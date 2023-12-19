// https://codeforces.com/problemset/problem/1902/C
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
int t, n, g, a[MAXN]; long long ans1, ans2, mx;

int main() {
    cin >> t;
    while (t--) {
        g = ans1 = 0, mx = LLONG_MIN;
        cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a, a + n); mx = a[n - 1];
        for (int i = 0; i < n; ++i) g = gcd(g, mx - a[i]);
        if (!g) {
            cout << 1 << endl; continue;
        }
        mx += g;
        for (int i = 0; i < n; ++i) ans1 += (mx - a[i]) / g;
        mx -= g;
        ans2 = -1;
        for (int i = n - 2; i >= 0; --i) {
            int prev = (mx - a[i + 1]) / g, curr = (mx - a[i]) / g;
            if (prev + 1 != curr) {
                ans2 = prev + 1; break;
            }
        }
        if (ans2 == -1) cout << ans1 << endl;
        else {
            for (int i = 0; i < n; ++i) ans2 += (mx - a[i]) / g;
            cout << min(ans1, ans2) << endl;
        }
    }
    return 0;
}
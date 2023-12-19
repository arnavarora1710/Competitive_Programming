// https://codeforces.com/problemset/problem/1903/C
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int t, n, a[MAXN]; long long suff[MAXN];

int main() {
    cin >> t;
    while (t--) {
        cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
        suff[n - 1] = a[n - 1]; for (int i = n - 2; i >= 0; --i) suff[i] = suff[i + 1] + a[i];
        long long ans = suff[0];
        for (int i = 1; i < n; ++i) ans += (suff[i] > 0 ? suff[i] : 0);
        cout << ans << endl;
    }
    return 0;
}
// https://codeforces.com/contest/1914/problem/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5;
int t, n, k, a[maxn], b[maxn];

signed main() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        for (int i = 1; i < n; ++i) a[i] += a[i - 1];
        for (int i = 1; i < n; ++i) b[i] = max(b[i], b[i - 1]);
        int ans = 0;
        for (int i = 0; i < min(n, k); ++i)
            ans = max(ans, a[i] + b[i] * (k - i - 1));
        cout << ans << endl;
    } 
    return 0;
}

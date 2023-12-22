// https://codeforces.com/contest/1888/problem/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, a[100005]; map<int, int> m;

signed main() {
    cin >> t;
    while (t--) {
        cin >> n; for (int i = 0; i < n; ++i) cin >> a[i]; m.clear();
        vector<int> b(n), suff(n);
        for (int i = n - 1; i >= 0; --i) {
            if (!m.count(a[i])) b[i] = 1, m[a[i]]++;
            suff[i] = (i + 1 < n ? suff[i + 1] : 0) + b[i];
        }
        m.clear(); int ans = 0;
        for (int i = 0; i < n; ++i)
            if (!m.count(a[i])) ans += suff[i], m[a[i]]++;
        cout << ans << endl;
    }
    return 0;
}
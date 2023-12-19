// https://codeforces.com/contest/1904/problem/C
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 1;
int t, n, k;

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> k; vector<long long> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        if (k >= 3) cout << 0 << endl;
        else {
            long long mn = LLONG_MAX, mn1 = LLONG_MAX;
            for (int i = 0; i < n; ++i) {
                mn = min(mn, a[i]); mn1 = min(mn1, a[i]);
                for (int j = i + 1; j < n; ++j) {
                    long long diff = abs(a[i] - a[j]);
                    mn = min(mn, diff);
                    int idx = lower_bound(a.begin(), a.end(), diff) - a.begin();
                    if (idx < n) mn1 = min(mn1, min(mn, abs(diff - a[idx])));
                    if (idx - 1 >= 0) mn1 = min(mn1, min(mn, abs(diff - a[idx - 1])));
                }
            }
            if (k == 1) cout << mn << endl;
            else cout << mn1 << endl;
        }
    }
    return 0;
}
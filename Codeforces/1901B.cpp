// https://codeforces.com/contest/1901/problem/B
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
int t, n, a[MAXN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin >> t;
    while (t--) {
        cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
        long long ans = a[0] - 1;
        for (int i = 1; i < n; ++i) if (a[i] > a[i - 1]) ans += a[i] - a[i - 1];
        cout << ans << endl;
    }
    return 0;
}
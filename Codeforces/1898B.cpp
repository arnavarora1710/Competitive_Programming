// https://codeforces.com/contest/1898/problem/B
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
int t, n, a[MAXN];

int main() {
    cin >> t;
    while (t--) {
        cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
        long long ans = 0; 
        for (int i = n - 2; i >= 0; --i) {
            int k = ceil(a[i] / (double) a[i + 1]);
            ans += k - 1, a[i] /= k;
        }
        cout << ans << endl;
    }
    return 0;
}
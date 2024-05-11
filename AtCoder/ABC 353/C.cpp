#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 3e5 + 5, inf = 1e18, mod = 1e8;
int n, a[maxn];

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    vector<int> suf(n);
    for (int i = n - 1; i >= 0; --i) 
        suf[i] = (i + 1 < n ? suf[i + 1] : 0) + a[i];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int l = i, r = n;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (a[i] + a[m] < mod) l = m;
            else r = m;
        }
        int iSum = (i + 1 < n ? suf[i + 1] : 0);
        int rSum = (r < n ? suf[r] : 0);
        // safe
        ans += (l - i) * a[i] + iSum - rSum;
        // danger
        ans += (((n - r) * (a[i] - mod)) + rSum);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
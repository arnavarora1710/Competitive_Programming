// https://codeforces.com/contest/1690/problem/E
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, k, a[maxn];

void solve() {
    cin >> n >> k; for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0; for (int i = 0; i < n; ++i) ans += a[i] / k, a[i] %= k;
    sort(a, a + n, greater<int>());
    int i = 0, j = n - 1;
    while (i < j) {
        while (i < j && a[i] + a[j] < k) j--;
        if (i == j) break;
        ans++, i++, j--;
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
// https://codeforces.com/problemset/problem/1917/C
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
const int maxn = 2000, maxk = 1e5;
int n, k, d, a[maxn], b[maxk];

void solve() {
    cin >> n >> k >> d;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < k; ++i) cin >> b[i];
    int ans = 0;
    if (a[0] == 0) ans = d/2;
    for (int i = 1; i <= max(min(d, n + 1), k); ++i) {
        int curr_payout = 0;
        for (int j = 0; j < n; ++j) {
            if (a[j] == j + 1) curr_payout++;
        }
        ans = max(ans, curr_payout + (d - i) / 2);
        for (int j = 0; j < b[(i - 1)%k]; ++j) a[j]++;
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
// https://codeforces.com/contest/1822/problem/G1
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, maxm = 1e6 + 5, inf = 1e18;
int n, a[maxn], m[maxm];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) m[a[i]]++;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (m[a[i]] - 1) * (m[a[i]] - 2);
        for (int j = 2; a[i] * j * j <= 1e6; ++j) {
            ans += m[a[i] * j] * m[a[i] * j * j];
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < n; ++i) m[a[i]]--;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
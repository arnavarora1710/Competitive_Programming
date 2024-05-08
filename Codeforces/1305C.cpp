// https://codeforces.com/problemset/problem/1305/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
int n, m, a[maxn];

void solve() {
    cin >> n >> m; for (int i = 0; i < n; ++i) cin >> a[i];
    if (n > m) cout << 0;
    else {
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans = (ans * abs(a[i] - a[j])) % m;
            }
        }
        cout << ans;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
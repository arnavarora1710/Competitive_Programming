// https://codeforces.com/contest/1946/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
int n, x, a[200005];

void solve() {
    cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int o = 0, xo = 0;
    for (int i = 0; i < n; ++i) o |= a[i], xo ^= a[i];
    if (xo > x) cout << -1 << endl;
    else if (o <= x) cout << n << endl;
    else {
        vector<vector<int>> bits(n, vector<int>(31));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= 30; ++j) {
                int bit = (a[i]) & (1 << j);
                bits[i][j] = bit;
            }
        }
        int ans = 0;
        for (int i = 30; i >= 0; --i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) cnt += bits[j][i];
            if (x & (1 << i)) {
                if (!(cnt&1)) {
                    ans = max(ans, cnt/2);
                    break;
                }
            } else {
                if (!(cnt&1)) {
                    ans = max(ans, cnt/2);
                    if (cnt) break;
                }
            }
        }
        cout << ans << endl;
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
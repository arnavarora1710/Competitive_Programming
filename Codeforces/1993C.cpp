// https://codeforces.com/contest/1993/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, k, a[maxn];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> dif(k + 1);
    int mx = *(max_element(a, a + n));
    int left = mx, right = mx + k - 1;
    for (int i = 0; i < n; ++i) {
        int l = -1, r = 1e9 + 5;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            int val = a[i] + 2 * m * k;
            if (val <= right) l = m;
            else r = m;
        }
        int cur_l = a[i] + 2 * l * k;
        int cur_r = cur_l + k - 1;
        if (cur_r < left) {
            cout << -1 << '\n';
            return;
        }
        cur_l = max(left, cur_l);
        cur_r = min(right, cur_r);
        // cerr << i << ' ' << l << ' ' << cur_l << ' ' << cur_r << '\n';
        dif[cur_l - mx]++, dif[cur_r - mx + 1]--;
    }
    for (int i = 1; i <= k; ++i) dif[i] += dif[i - 1];
    // for (int i = 0; i <= k; ++i) {
    //     cerr << dif[i] << ' ';
    // }
    // cerr << '\n';
    for (int i = 0; i <= k; ++i) {
        if (dif[i] == n) {
            cout << i + mx << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

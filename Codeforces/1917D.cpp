// https://codeforces.com/contest/1917/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
const int maxn = 200005, mod = 998244353;
const int MOD_INV_2 = 499122177;
int n, k, p[maxn], q[maxn];
vector<int> tr(4 * maxn);

int query(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        ret += tr[r];
    return ret;
}

int query(int l, int r) {
    if (!l) return query(r);
    return query(r) - query(l - 1);
}

void update(int idx, int delta) {
    for (; idx < 4 * maxn; idx = idx | (idx + 1))
        tr[idx] += delta;
}

void solve() {
    cin >> n >> k; 
    for (int i = 0; i < n; ++i) cin >> p[i];
    for (int i = 0; i < k; ++i) cin >> q[i];

    // count in-group inversions for q
    tr.assign(4 * max(n, k), 0);
    int ans = 0;
    for (int i = k - 1; i >= 0; --i) {
        int lower = query(q[i]);
        ans = (ans + lower) % mod;
        update(q[i], 1);
    }
    ans = (ans * n) % mod;
    
    // count in-group inversions for p
    tr.assign(4 * max(n, k), 0);
    int ans1 = 0;
    for (int i = n - 1; i >= 0; --i) {
        int lower = query(p[i]);
        ans1 = (ans1 + lower) % mod;
        update(p[i], 1);
    }
    ans1 = (ans1 * k) % mod;
    ans = (ans + ans1) % mod;

    // count other inversions
    tr.assign(4 * max(n, k), 0);    
    for (int i = 0; i < n; ++i) {
        // inversions of the form x < 2^m y
        // where index(x) > index(y) 
        int cnt = 1;
        for (int j = 1; j < k; ++j) {
            if ((p[i] >> j) == 0) break;
            int big = i - query(p[i] >> j);
            ans = (ans + big * (k - j)) % mod;
            cnt++;
        }

        // when (p[i] >> j) goes too low, then everything is an inversion
        ans = (ans + (k - cnt) * (k - cnt + 1) % mod * MOD_INV_2 % mod * i) % mod;

        // inversions of the form x > 2^m y
        // where index(x) > index(y) 
        for (int j = 1; j < k; ++j) {
            if ((p[i] << j) >= 4 * max(n, k)) break;
            int big = i - query(p[i] << j);
            ans = (ans + big * (k - j)) % mod;
        }
        update(p[i], 1);
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
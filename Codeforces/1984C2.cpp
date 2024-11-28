// https://codeforces.com/contest/1984/problem/C2
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
const int maxn = 2e5 + 5, inf = 1e18, mod = 998244353;
int n, a[maxn];

int power(int x, int y) {
    int res = 1;
    while (y) {
        if (y&1) res = (res * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return res;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int c = 0, cnt = 0;
    vector<pi> tot;
    vector<int> state(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (c + a[i] >= 0) c += a[i], cnt++;
        else {
            c += a[i];
            tot.push_back({abs(2 * c), i});
        }
        state[i] = c;
    }
    if (tot.empty()) {
        cout << power(2, cnt) << '\n';
    } else {
        int ans = c;
        for (pi i : tot) {
            ans = max(ans, c + i.f);
        }
        vector<int> new_state(n + 1);
        for (int i = 1; i <= n; ++i) 
            new_state[i] = state[i] + ans - c;
        vector<int> suf(n + 2);
        vector<int> pre(n + 1);
        for (int i = 1; i <= n; ++i) {
            suf[i] += (new_state[i] >= 0);
            pre[i] += (state[i] >= 0);
        }
        for (int i = 2; i <= n; ++i)
            pre[i] += pre[i - 1];
        for (int i = n - 1; i >= 1; --i)
            suf[i] += suf[i + 1];
        // int ans = 0;
        // for (int i : state) cerr << i << ' ';
        // cerr << '\n';
        // for (int i : new_state) cerr << i << ' ';
        // cerr << '\n';
        // for (int i : suf) cerr << i << ' ';
        // cerr << '\n';

        // int cnt1 = 0;
        int res = 0;
        for (pi i : tot) {
            if (c + i.f == ans) {
                int p = power(2, pre[i.s - 1]);
                int s = power(2, suf[i.s + 1]);
                // cerr << i.s << ' ' << p << ' ' << s << '\n';
                res = (res + (p * s) % mod) % mod;
            }
        }
        cout << res << '\n';
        // cerr << cnt << ' ' << cnt1 << '\n';
        // cout << (power(2, cnt) * (power(2, cnt1) - 1)) % mod << '\n';
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

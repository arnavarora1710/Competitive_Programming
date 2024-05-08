// https://codeforces.com/contest/1833/problem/F
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, mod = 1e9 + 7;
int n, m, a[maxn];

int power(int aa, int bb) {
    int res = 1;
    while (bb) {
        if (bb&1) res = (res * aa) % mod;
        aa = (aa * aa) % mod;
        bb >>= 1;
    }
    return res;
}

int inv(int nn) {
    return power(nn, mod - 2);
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) cnt[a[i]]++;
    set<int> s(a, a + n);
    vector<int> b(s.begin(), s.end());
    vector<int> pr(b.size());
    for (int i = 0; i < b.size(); ++i)
        pr[i] = cnt[b[i]];
    for (int i = 1; i < b.size(); ++i)
        pr[i] = (pr[i] * pr[i - 1]) % mod;
    int i = 0, j = m - 1, ans = 0;
    while (j < b.size()) {
        int val = (pr[j] * inv((i ? pr[i - 1] : 1))) % mod;
        if (b[j] - b[i] < m) ans = (ans + val) % mod;
        i++, j++;
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
// https://codeforces.com/contest/923/problem/B
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
int n, a[maxn], b[maxn];

void solve() {
    cin >> n; 
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    vector<int> pr(n), dif(n + 2), sub(n);
    for (int i = 0; i < n; ++i) pr[i] = (i ? pr[i - 1] : 0) + b[i];
    for (int i = 0; i < n; ++i) {
        int l = i - 1, r = n;
        int p = (i ? pr[i - 1] : 0);
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (pr[m] - p <= a[i]) l = m;
            else r = m;
        }
        if (r < n)
            sub[r] += a[i] - pr[r] + p;
        dif[r + 1]--;
    }
    for (int i = 1; i <= n; ++i) dif[i] += dif[i - 1];
    for (int i = 0; i < n; ++i) {
        int val = (i + 1 + dif[i]) * b[i] + sub[i];
        cout << val << ' ';
    }
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

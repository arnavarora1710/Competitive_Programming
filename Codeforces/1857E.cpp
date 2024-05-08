// https://codeforces.com/contest/1857/problem/E
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
int n, a[maxn];

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> ans(n);
    vector<pi> b(n);
    for (int i = 0; i < n; ++i) b[i] = {a[i], i};
    sort(b.begin(), b.end());
    vector<int> pr(n); pr[0] = b[0].f;
    for (int i = 1; i < n; ++i) 
        pr[i] = pr[i - 1] + b[i].f;
    for (int i = 0; i < n; ++i) {
        int val = i ? pr[i - 1] : 0;
        val = i * b[i].f - val;
        int val1 = pr[n - 1] - pr[i];
        val1 -= (n - i - 1) * b[i].f;
        ans[b[i].s] = val + val1 + n;
    }
    for (int i : ans) cout << i << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
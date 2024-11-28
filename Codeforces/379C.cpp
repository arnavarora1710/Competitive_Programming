// https://codeforces.com/contest/379/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (0)
const int maxn = 3e5 + 5, inf = 1e18;
int n, a[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<pi> b;
    for (int i = 0; i < n; ++i) b.push_back({a[i], i});
    sort(b.begin(), b.end());
    vector<int> ans(n);
    int p = 1;
    for (int i = 0; i < n; ++i) {
        int val = max(b[i].f, p);
        ans[b[i].s] = val;
        p = val + 1;
    }
    for (int i : ans) cout << i << ' ';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

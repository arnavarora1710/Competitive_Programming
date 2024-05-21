// https://codeforces.com/contest/1779/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, m, a[maxn];

void solve() {
    cin >> n >> m; for (int i = 0; i < n; ++i) cin >> a[i];
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq1;
    int ans = 0, cur = 0;
    for (int i = m - 1; i > 0; --i) {
        cur += a[i];
        if (a[i] > 0) pq.push(a[i]);
        while (cur > 0) {
            int tp = pq.top();
            pq.pop();
            ans++;
            cur -= 2 * tp;
        }
    }
    cur = 0;
    for (int i = m; i < n; ++i) {
        cur += a[i];
        if (a[i] < 0) pq1.push(a[i]);
        while (cur < 0) {
            int tp = pq1.top();
            pq1.pop();
            ans++;
            cur -= 2 * tp;
        }
    }
    cout << ans << '\n';
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

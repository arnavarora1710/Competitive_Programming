#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
const int maxn = 200005;
int n, x, y, q, a[maxn], id[maxn];

void solve() {
    cin >> n >> q; for (int i = 0; i < n; ++i) cin >> a[i], id[a[i]] = i;
    int ans = 1; id[n + 1] = n + 1;
    for (int i = 2; i <= n; ++i) {
        if (id[i] < id[i - 1]) ans++;
    }
    while (q--) {
        cin >> x >> y; x--, y--;
        if (id[a[x] - 1] <= id[a[x]] && id[a[x] - 1] > y) ans++;
        if (id[a[x] - 1] > id[a[x]] && id[a[x] - 1] <= y) ans--;
		if (id[a[x]] <= id[a[x] + 1] && y > id[a[x] + 1]) ans++;
        if (id[a[x]] > id[a[x] + 1] && y <= id[a[x] + 1]) ans--;
		id[a[x]] = y;
        if (id[a[y] - 1] <= id[a[y]] && id[a[y] - 1] > x) ans++;
        if (id[a[y] - 1] > id[a[y]] && id[a[y] - 1] <= x) ans--;
		if (id[a[y]] <= id[a[y] + 1] && x > id[a[y] + 1]) ans++;
        if (id[a[y]] > id[a[y] + 1] && x <= id[a[y] + 1]) ans--;
		id[a[y]] = x;
        swap(a[x], a[y]);
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
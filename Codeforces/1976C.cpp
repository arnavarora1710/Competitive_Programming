// https://codeforces.com/contest/1976/problem/C
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
int n, m, a[maxn], b[maxn];

void solve() {
    cin >> n >> m;
    for (int i = 0; i <= n + m; ++i) cin >> a[i];
    for (int j = 0; j <= n + m; ++j) cin >> b[j];
    vector<int> ind, ind1, choice(n + m + 1);
    int ans = 0, nn = n, mm = m;
    for (int i = 0; i <= n + m; ++i) {
        if (a[i] < b[i]) {
            if (mm) ans += b[i], mm--, choice[i] = b[i];
            else if (nn) ans += a[i], nn--, choice[i] = a[i], ind1.push_back(i);
        } else {
            if (nn) ans += a[i], nn--, choice[i] = a[i];
            else if (mm) ans += b[i], mm--, choice[i] = b[i], ind.push_back(i);
        }
    }
    if (a[n + m] > b[n + m]) ind.push_back(n + m);
    else ind1.push_back(n + m);
    for (int i = 0; i < n + m; ++i) {
        int res = ans - choice[i];
        if (choice[i] == b[i]) {
            auto it = upper_bound(ind1.begin(), ind1.end(), i);
            if (it != ind1.end()) {
                int index = it - ind1.begin();
                res += b[ind1[index]] - choice[ind1[index]];
                if (ind1[index] != n + m) res += a[n + m];
            } else res += b[n + m];
        }
        else {
            auto it = upper_bound(ind.begin(), ind.end(), i);
            if (it != ind.end()) {
                int index = it - ind.begin();
                res += a[ind[index]] - choice[ind[index]];
                if (ind[index] != n + m) res += b[n + m];
            } else res += a[n + m];
        }
        cout << res << ' ';
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

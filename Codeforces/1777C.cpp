// https://codeforces.com/contest/1777/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 1e5 + 5, inf = 1e18;
int n, m, a[maxn], done[maxn];
set<int> factors[maxn];

void init() {
    for (int i = 1; i < maxn; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            if (i % j == 0) {
                factors[i].insert(j);
                factors[i].insert(i / j);
            }
        }
    }
}

void solve() {
    cin >> n >> m; for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i <= m; ++i) done[i] = 0;
    sort(a, a + n);
    int ct = 0, k = 0, ans = inf;
    for (int i = 0; i < n; ++i) {
        for (int j : factors[a[i]]) {
            if (j > m) break;
            if (!done[j]++) ct++;
        }
        while (ct == m) {
            ans = min(ans, a[i] - a[k]);
            for (int j : factors[a[k]]) {
                if (j > m) break;
                if (--done[j] == 0) ct--;
            }
            k++;
        }
    }
    cout << (ans >= inf ? -1 : ans) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    init();

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
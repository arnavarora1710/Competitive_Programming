// https://codeforces.com/contest/1995/problem/C
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
const int maxn = 2e5 + 5, inf = 1e18;
int n, a[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    bool ok = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            if (!ok) {
                cout << -1 << '\n';
                return;
            }
        } else ok = 0;
    }
    int ans = 0;
    int pr = 0;
    for (int i = 1; i < n; ++i) {
        int p = a[i - 1], c = a[i], t = 0;
        while (p != 1 && p * p <= c) t--, p *= p;
        while (c < p) c *= c, t++;
        pr = max(0LL, pr + t);
        ans += pr;
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

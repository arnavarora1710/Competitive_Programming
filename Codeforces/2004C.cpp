// https://codeforces.com/contest/2004/problem/C
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
int n, k, a[maxn];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    reverse(a, a + n);
    for (int i = 1; i < n; i += 2) {
        int diff = -a[i];
        a[i] = min(a[i - 1], a[i] + k);
        diff += a[i];
        k -= diff;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i&1) ans -= a[i];
        else ans += a[i];
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

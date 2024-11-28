// https://codeforces.com/contest/1995/problem/B1
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
int n, k;
pi b[maxn];
map<int, int> cnt;

int calc(int i, int k1) {
    int k2 = min(cnt[b[i].f + 1], (k - k1 * b[i].f) / (b[i].f + 1));
    int spent = b[i].f * k1 + (b[i].f + 1) * k2;
    int cur = k - spent;
    int r = min(k1, min(cnt[b[i].f + 1] - k2, cur));
    return (k1 - r) * b[i].f + (k2 + r) * (b[i].f + 1);
}

void solve() {
    cin >> n >> k; cnt.clear();
    for (int i = 0; i < n; ++i) cin >> b[i].f;
    for (int i = 0; i < n; ++i) cin >> b[i].s;
    for (int i = 0; i < n; ++i) cnt[b[i].f] = b[i].s;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int k1 = min(cnt[b[i].f], k / b[i].f);
        ans = max(ans, calc(i, k1));
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

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

bool check(int m) {
    int kk = k - 1, cur = 0;
    for (int i = 1; i < n; ++i) {
        if (!kk) break;
        if (cur >= m) kk--, cur = 0;
        cur += a[i] - a[i - 1];
    }
    if (cur >= m) kk--;
    kk = max(0LL, kk);
    return !kk;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    int l = -1, r = inf;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    cout << l << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

// https://codeforces.com/problemset/problem/776/C
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
int n, k, a[maxn];
set<int> vis;

int power(int x, int y) {
    int res = 1;
    while (y) {
        if (y&1) res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    for (int pw = 0; ; ++pw) {
        int x = power(k, pw);
        if (vis.find(x) != vis.end()) break;
        vis.insert(x);
        if (x > 1e15) break;
        map<int, int> cnt;
        cnt[0] = 1;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
            ans += cnt[sum - x];
            cnt[sum]++;
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

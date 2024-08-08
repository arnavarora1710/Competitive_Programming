// https://codeforces.com/contest/1985/problem/F
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
int h, n, a[maxn], b[maxn];

bool check(int m) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (ans >= h) return true;
        int div = (m - 1) / b[i] + 1;
        if (ans + div >= h) return true;
        ans += div * a[i];
    }
    return ans >= h;
}

void solve() {
    cin >> h >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    int l = 0, r = inf;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (!check(m)) l = m;
        else r = m;
    }
    cout << r << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

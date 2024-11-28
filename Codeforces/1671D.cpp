// https://codeforces.com/contest/1671/problem/D
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template<class T> using omset = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define int long long
#define f first
#define s second
#define MULTI_TEST (1)

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

const int N = 200005, INF = 1e18, MOD = 1e9 + 7;
int n, k, q, x, y, u, v, a[N];

void solve() {
    cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    for (int i = 0; i + 1 < n; ++i)
        ans += abs(a[i] - a[i + 1]);
    int mn = INF, mx = -INF;
    for (int i = 0; i < n; ++i) {
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    int mn1 = INF, mn2 = INF;
    for (int i = 0; i < n; ++i) {
        if (i) mn1 = min(mn1, a[i - 1] - 1 + a[i] - 1 - abs(a[i - 1] - a[i]));
        else mn1 = min(mn1, a[i] - 1);
        if (i + 1 < n) mn1 = min(mn1, a[i + 1] - 1 + a[i] - 1 - abs(a[i + 1] - a[i]));
        else mn1 = min(mn1, a[i] - 1);
        if (i) mn2 = min(mn2, max(0LL, x - a[i - 1]) + max(0LL, x - a[i]) - abs(a[i - 1] - a[i]));
        else mn2 = min(mn2, max(0LL, x - a[i]));
        if (i + 1 < n) mn2 = min(mn2, max(0LL, x - a[i + 1]) + max(0LL, x - a[i]) - abs(a[i + 1] - a[i]));
        else mn2 = min(mn2, max(0LL, x - a[i]));
    }
    if (mn <= 1) mn1 = 0;
    if (mx >= x) mn2 = 0;
    cout << ans + mn1 + mn2 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}
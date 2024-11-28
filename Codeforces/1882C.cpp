// https://codeforces.com/contest/1882/problem/C
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
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    vi so(n), se(n), s(n);
    for (int i = n - 1; i >= 0; --i) {
        if (i&1) se[i] = (i + 2 < n ? se[i + 2] : 0) + max(0LL, a[i]);
        else so[i] = (i + 2 < n ? so[i + 2] : 0) + max(0LL, a[i]);
        s[i] = (i + 1 < n ? s[i + 1] : 0) + max(0LL, a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i&1) 
            ans = max({ans, (i + 1 < n ? s[i + 1] : 0), (i + 2 < n ? se[i + 2] : 0)});
        else
            ans = max({ans, so[i], a[i] + (i + 1 < n ? s[i + 1] : 0)});
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}
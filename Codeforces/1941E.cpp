// https://codeforces.com/contest/1941/problem/E
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
int n, m, d, k, q, x, y, u, v;

void solve() {
    cin >> n >> m >> k >> d; vii a(n, vi(m));
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    vi dp(m), p(n);
    for (int i = 0; i < n; ++i) {
        dp[0] = 1;
        set<pi> s = {{1, 0}};
        for (int j = 1; j < m; ++j) {
            dp[j] = s.begin()->f + a[i][j] + 1;
            s.insert({dp[j], j});
            if (j - d - 1 >= 0)
                s.erase(s.find({dp[j - d - 1], j - d - 1}));
        }
        p[i] = dp.back();
    }
    for (int i = 1; i < n; ++i) p[i] += p[i - 1];
    int ans = INF;
    for (int i = 0; i + k - 1 < n; ++i) {
        int sum = p[i + k - 1] - (i ? p[i - 1] : 0);
        ans = min(ans, sum);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}
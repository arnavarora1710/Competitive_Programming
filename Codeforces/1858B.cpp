// https://codeforces.com/contest/1858/problem/B
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
int n, m, k, q, x, y, u, v;

void solve() {
    cin >> n >> m >> k;
    vi a(m);
    for (int i = 0; i < m; ++i) cin >> a[i]; 
    vi p(m), s(m);
    for (int i = 0; i < m; ++i) 
        p[i] = (i ? p[i - 1] : 0) + (i ? (a[i] - a[i - 1] - 1) / k + 1 : max(0LL, a[i] - 2) / k + (a[i] != 1));
    for (int i = m - 1; i >= 0; --i) 
        s[i] = (i + 1 < m ? s[i + 1] : 0) + (i + 1 < m ? (a[i + 1] - a[i] - 1) / k + 1 : max(0LL, n - a[i]) / k);
    map<int, int> ans;
    for (int i = 0; i < m; ++i) {
        int val;
        if (i == 0) {
            val = max(0LL, a[i + 1] - 2) / k + 2 + s[i + 1];
        } else if (i == m - 1) {
            val = p[i - 1] + max(0LL, n - a[i - 1]) / k + 1;
        } else {
            val = p[i - 1] + (a[i + 1] - a[i - 1] - 1) / k + 2 + s[i + 1];
        }
        ans[val]++;
    }
    cout << ans.begin()->f << ' ' << ans.begin()->s << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}
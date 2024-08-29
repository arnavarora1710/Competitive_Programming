// https://codeforces.com/contest/1968/problem/F
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
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];
    vi p(n);
    map<int, vi> m;
    for (int i = 0; i < n; ++i) {
        p[i] = (i ? p[i - 1] : 0) ^ a[i];
        m[p[i]].push_back(i);
    }
    while (q--) {
        cin >> x >> y; x--, y--;
        int bef = (x ? p[x - 1] : 0);
        int xo = p[y] ^ bef;
        if (!xo) cout << "YES\n";
        else {
            xo ^= bef;
            int id = lower_bound(m[xo].begin(), m[xo].end(), x) - m[xo].begin();
            int id0 = lower_bound(m[bef].begin(), m[bef].end(), m[xo][id]) - m[bef].begin();
            if (id >= 0 && id < m[xo].size() && m[xo][id] >= x && m[xo][id] < y && id0 >= 0 && id0 < m[bef].size() && m[bef][id0] > id && m[bef][id0] < y) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}
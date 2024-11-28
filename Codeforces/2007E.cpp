// https://codeforces.com/contest/2007/problem/E
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
int n, k, q, x, y, u, v, p[N];

void solve() {
    cin >> n >> k;
    for (int i = 2; i <= n; ++i) cin >> p[i];
    // fen/seg tree? 
    // keep track of fully filled out paths?
    // every edge occurs twice
    // the answer for dist(i, i mod n + 1) is always w - sum of all nodes not in path
    int ans = k * n;
    for (int i = 0; i + 1 < n; ++i) {
        cin >> x >> y;
        ans -= (n - 2) * y;
        if (p[x] == x - 1) ans -= k - y;
        cout << ans << ' ';
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}
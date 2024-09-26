// https://codeforces.com/contest/2005/problem/B1
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
int n, m, q, x, y, u, v, a[2];

void solve() {
    cin >> n >> m >> q;
    for (int i = 0; i < m; ++i) cin >> a[i];
    cin >> x;
    sort(a, a + 2);
    if (a[0] <= x && x <= a[1]) {
        if ((a[0] + a[1])&1) {
            cout << (a[0] + a[1]) / 2 - a[0] << '\n';
        } else {
            cout << a[1] - (a[0] + a[1]) / 2 << '\n';
        }
    }
    else if (x < a[0]) {
        a[0] -= x - 1;
        cout << x - 1 + a[0] - 1 << '\n';
    }
    else {
        a[1] += n - x;
        cout << n - x + n - a[1] << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}
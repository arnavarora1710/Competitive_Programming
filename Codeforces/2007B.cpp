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
int n, m, k, q, x, y, u, v, a[N];

void solve() {
    cin >> n >> m;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    int mx = a.back();
    while (m--) {
        char tp; cin >> tp;
        cin >> x >> y;
        if (a.back() >= x && a.back() <= y) {
            if (tp == '+') {
                a.back()++;
                mx = a.back();
            }
            else {
                a.back()--;
                mx = a.back();
            }
        }
        cout << mx << ' ';
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}
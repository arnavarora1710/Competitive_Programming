// https://codeforces.com/contest/1353/problem/D
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

class Compare {
    public:
        bool operator()(vi& x, vi& y) {
            if (x[0] == y[0]) return x[1] > y[1];
            else return x[0] < y[0];
        }
};

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) a[i] = 0;
    priority_queue<vi, vii, Compare> pq;
    pq.push({n, 0, n - 1});
    int cur = 1;
    while (!pq.empty()) {
        auto x = pq.top(); pq.pop();
        int len = x[0], l = x[1], r = x[2];
        int m = l + (r - l) / 2;
        a[m] = cur++;
        if (l <= m - 1) pq.push({m - l, l, m - 1});
        if (r >= m + 1) pq.push({r - m, m + 1, r});
    }
    for (int i = 0; i < n; ++i) cout << a[i] << ' ';
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}
// https://codeforces.com/contest/1980/problem/E
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

vii transpose(vii& a) {
    int N = a.size(), M = a[0].size();
    vii b(M, vi(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            b[j][i] = a[i][j];
    return b;
}

void solve() {
    cin >> n >> m;
    vii a(n, vi(m)), b(n, vi(m));
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j)
            cin >> b[i][j];
    map<int, pi> id1, id2;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            id1[a[i][j]] = {i, j}, id2[b[i][j]] = {i, j};
    swap(a[id1[1].f], a[id2[1].f]);
    int row1 = id2[1].f;
    vii c = transpose(a);
    map<int, int> ind;
    for (int j = 0; j < m; ++j) {
        ind[b[row1][j]] = j;
    }
    for (auto& x : ind) {
        if (b[row1][x.s] != c[x.s][row1]) {
            id1[c[x.s][row1]].s = id1[x.f].s;
            swap(c[id1[x.f].s], c[x.s]);
        }
    }
    a = transpose(c);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << (a == b ? "YES\n" : "NO\n");
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}
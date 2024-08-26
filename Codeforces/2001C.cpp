// https://codeforces.com/contest/2001/problem/C
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

int ask(int u, int v) {
    cout << "? " << u << " " << v << endl;
    int x; cin >> x;
    assert(x != -1);
    return x;
}

void submit(set<pi>& ans) {
    cout << "! ";
    for (auto& x : ans)
        cout << x.f << " " << x.s << " ";
    cout << endl;
}

void solve() {
    cin >> n;
    set<pi> edges;
    vi vis(n + 1);
    auto f = [&](auto&& f, int l, int r) {
        if (vis[r]) return;
        int m = ask(l, r);
        if (m == l) {
            edges.insert({l, r});
            vis[l] = vis[r] = true;
        } else {
            f(f, l, m);
            f(f, m, r);
        }
    };
    for (int i = 2; i <= n; ++i)
        f(f, 1, i);
    // assert(edges.size() == n - 1);
    submit(edges);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}
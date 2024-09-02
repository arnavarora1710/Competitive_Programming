// https://codeforces.com/contest/2008/problem/D
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
string s;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cin >> s;
    vii adj(n + 1);
    for (int i = 1; i <= n; ++i) {
        adj[i].push_back(a[i]);
        adj[a[i]].push_back(i);
    }
    vi vis(n + 1), col(n + 1);
    queue<int> q;
    int cur = 1;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            col[i] = cur;
            vis[i] = true;
            q.push(i);
            while (!q.empty()) {
                int tp = q.front(); q.pop();
                for (auto& cc : adj[tp]) {
                    if (!vis[cc]) {
                        col[cc] = cur;
                        vis[cc] = true;
                        q.push(cc);
                    }
                }
            }
            cur++;
        }
    }
    vi f(n + 1);
    for (int i = 1; i <= n; ++i)
        if (s[i - 1] == '0')
            f[col[i]]++;
    for (int i = 1; i <= n; ++i)
        cout << f[col[i]] << ' ';
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}
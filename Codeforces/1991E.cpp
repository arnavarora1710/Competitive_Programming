// https://codeforces.com/contest/1991/problem/E
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
vii a;
vi col;

bool bfs() {
    col.resize(n + 1);
    fill(col.begin(), col.end(), -1);
    col[1] = 1;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int tp = q.front(); q.pop();
        for (auto& cc : a[tp]) {
            if (col[cc] == -1) {
                col[cc] = 1 - col[tp];
                q.push(cc);
            } else if (col[cc] == col[tp]) return true;
        }
    }
    return false;
}

void solve() {
    cin >> n >> m;
    a.clear();
    a.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    } 
    if (bfs()) {
        cout << "Alice" << endl;
        for (int i = 1; i <= n; ++i) {
            cout << 1 << " " << 2 << endl;
            cin >> x >> x;
        }
    } else {
        set<int> one, two;
        for (int i = 1; i <= n; ++i) {
            if (col[i]) one.insert(i);
            else two.insert(i);
        }
        cout << "Bob" << endl;
        for (int i = 1; i <= n; ++i) {
            cin >> x >> y;
            set<int> s = {x, y};
            if (s.find(1) != s.end()) {
                if (!one.empty()) {
                    cout << *(one.begin()) << " " << 1 << endl;
                    one.erase(one.begin());
                }
                else {
                    cout << *(two.begin()) << " " << *(s.rbegin()) << endl;
                    two.erase(two.begin());
                }
            } else {
                if (!two.empty()) {
                    cout << *(two.begin()) << " " << 2 << endl;
                    two.erase(two.begin());
                }
                else { 
                    cout << *(one.begin()) << " " << 3 << endl;
                    one.erase(one.begin());
                }
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template<class T> using omset = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << "\033[1;31m" << name << " : " << arg1 << "\033[0m" << endl; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr << "\033[1;31m" << string(names, comma - names) << " : " << arg1 << "\033[0m |";
    __f(comma + 1, args...);
}

// #define int long long
#define double long double
#define f first
#define s second
#define db(x, a, b) for (int i = (a); i <= (b); ++i) cerr << "\033[1;31m" << x[i] << "\033[0m "; cerr << '\n'
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define repr(i, a, b) for (int i = (a); i >= (b); --i)
#define MULTI_TEST (1)

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vii;
typedef vector<vpi> vpii;
typedef priority_queue<int> pqmx;
typedef priority_queue<int, vi, greater<int>> pqmn;

const int N = 2e6 + 5, mod = 1e9 + 7;
const double PI = acos(-1), EPS = 1e-9;
int n, m, k, q, x, y, u, v, a[N];
vii adj_new;
vpii adj;

void solve() {
    cin >> n >> m;
    adj.clear(); adj_new.clear();
    adj.resize(n+1); adj_new.resize(n+1);
    rep(i,1,m) {
        cin >> u >> v >> x;
        adj[u].push_back({v,x});
        adj[v].push_back({u,x});
    }
    int ans = INT_MAX;
    auto check = [&] (int x, int y) {
        repr(i,30,0) {
            int bitX = (x>>i)&1;
            int bitY = (y>>i)&1;
            if (bitX and !bitY) return false;
        }
        return true;
    };
    queue<int> q;
    vi vis(n+1);
    repr(i,30,0) {
        int pot_ans = ans ^ (1 << i);
        rep(j,1,n) {
            adj_new[j].clear();
            for (auto [cc, ww] : adj[j]) {
                if (check(ww, ans^(1LL<<i))) {
                    adj_new[j].push_back(cc);
                }
            }
        }
        q.push(1);
        fill(vis.begin(), vis.end(), 0);
        vis[1] = true;
        while (!q.empty()) {
            int tp = q.front(); q.pop();
            for (auto& cc : adj_new[tp]) {
                if (!vis[cc]) {
                    vis[cc] = true;
                    q.push(cc);
                }
            }
        }
        bool can = 1;
        rep(j,1,n) can &= vis[j];
        if (can) ans ^= (1LL << i);
    }
    cout << ans << '\n';
}

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}

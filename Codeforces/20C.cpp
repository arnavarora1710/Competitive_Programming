#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template<class T> using omset = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " |"; __f(comma + 1, args...);
}

#define int long long
#define double long double
#define f first
#define s second
#define db(x, a, b) for (int i = (a); i <= (b); ++i) cerr << x[i] << " "; cerr << '\n'
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define repr(i, a, b) for (int i = (a); i >= (b); --i)
#define MULTI_TEST (0)

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vii;
typedef vector<vpi> vpii;
typedef priority_queue<int> pqmx;
typedef priority_queue<pi, vpi, greater<pi>> pqmn;

const int N = 2e6 + 5, inf = 1e18, mod = 1e9 + 7;
const double PI = acos(-1), EPS = 1e-9;
int n, m, k, q, x, y, u, v, a[N];
vector<map<int, int>> adj;

void solve() {
    cin >> n >> m;
    adj.resize(n + 1);
    rep(i,1,m) {
        cin >> u >> v >> x;
        if (u == v) continue;
        if (adj[u].count(v))
            adj[u][v] = min(adj[u][v], x);
        else
            adj[u][v] = x;
        if (adj[v].count(u))
            adj[v][u] = min(adj[v][u], x);
        else
            adj[v][u] = x;
    }
    pqmn pq;
    vi d(n+1, inf), p(n+1, -1);
    p[1] = -1;
    d[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [ww, nn] = pq.top(); pq.pop();
        if (d[nn] < ww) continue;
        for (auto& v : adj[nn]) {
            int nw = ww + v.s;
            if (d[v.f] > nw) {
                d[v.f] = nw;
                p[v.f] = nn;
                pq.push({nw, v.f});
            }
        }
    }
    if (p[n] == -1) cout << -1;
    else {
        int nn = n;
        vi ans;
        while (nn != -1) {
            ans.push_back(nn);
            nn = p[nn]; 
        }
        reverse(ans.begin(), ans.end());
        for (auto& x : ans) cout << x << ' ';
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}

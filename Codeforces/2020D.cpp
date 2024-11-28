// http://codeforces.com/contest/2020/problem/D
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
#define MULTI_TEST (1)

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef priority_queue<int> pqmx;
typedef priority_queue<int, vi, greater<int>> pqmn;

const int N = 2e5 + 5, inf = 1e18, mod = 1e9 + 7;
const double PI = acos(-1), EPS = 1e-9;
int n, k, q, x, y, u, v;
int mp[11][10][N];

class dsu {
	vi par, sz;
	public:
		dsu(int m) {
			par.resize(m + 1, 0);
			sz.resize(m + 1, 1);
            iota(par.begin(), par.end(), 0);
		}
		int find(int m) {
            return (par[m] == m ? m : par[m] = find(par[m]));
		}
		void uni(int u, int v) {
            int up = find(u), vp = find(v);
            if (up == vp) return;
            if (sz[up] < sz[vp]) par[up] = vp, sz[vp] += sz[up];
            else par[vp] = up, sz[up] += sz[vp];
		}
};

void solve() {
    cin >> n >> q;
    rep(i, 1, 10)
        rep(j, 0, 9) 
            rep(k, 1, n + 1)
                mp[i][j][k] = 0;
    rep(i, 1, q) {
        int a, d, k;
        cin >> a >> d >> k;
        if (k) {
            int x = a, y = a + (k - 1) * d;
            mp[d][a % d][x]++, mp[d][a % d][y + 1]--;
        }
    }
    dsu d = *(new dsu(n + 1));
    rep(x, 1, 10) {
        rep(y, 0, x - 1) {
            rep(i, 1, n) mp[x][y][i] += mp[x][y][i - 1];
            for (int i = y; i + x <= n; i += x) 
                if (mp[x][y][i])
                    d.uni(i, i + x);
        }
    }
    int ans = 0;
    rep(i, 1, n) ans += d.find(i) == i;
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}
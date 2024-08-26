// https://codeforces.com/contest/1994/problem/D
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

const int N = 2005, INF = 1e18, MOD = 1e9 + 7;
int n, k, q, x, y, u, v, a[N];

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
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    dsu d(n);
    vii ans;
    cout << "YES\n";
    for (int op = n - 1; op >= 1; --op) {
        map<int, map<int, int>> mp;
        for (int i = 0; i < n; ++i) {
            if (mp[a[i] % op].size() > 1) continue;
            mp[a[i] % op][d.find(i)] = i;
        }
        for (auto& x : mp) {
            int sz = x.s.size();
            if (sz > 1) {
                int u = (x.s.begin())->s;
                int v = (x.s.rbegin())->s;
                ans.push_back({u + 1, v + 1});
                d.uni(u, v);
                break;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto& x : ans) {
        for (auto& y : x) cout << y << ' ';
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}
// http://codeforces.com/contest/2034/problem/D
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
typedef vector<pi> vpi;
typedef vector<vi> vii;
typedef vector<vpi> vpii;
typedef priority_queue<int> pqmx;
typedef priority_queue<int, vi, greater<int>> pqmn;

const int N = 2e6 + 5, inf = 1e18, mod = 1e9 + 7;
const double PI = acos(-1), EPS = 1e-9;
int n, k, q, x, y, u, v, a[N];

void solve() {
    cin >> n;
    rep(i,1,n) cin >> a[i];
    map<int, int> mp;
        rep(i,1,n) mp[a[i]] = (mp.count(a[i]) ? min(mp[a[i]], i) : i);
        int l = 1, m = 1, r = n;
        vpi ans;
        while (m <= r) {
            // bug(l, m, r, mp[1]);
            if (a[m] == 0) {
                if (a[l] == 1) {
                    if (mp[1] == l) mp[1] = m;
                    ans.push_back({l, m});
                }
                swap(a[l++], a[m++]);
            }
            else if (a[m] == 1) {
                m++;
            } else {
                if (a[m] != a[r]) {
                    if (a[r] == 1) {
                        if (mp[1] == r) mp[1] = m;
                        ans.push_back({m, r});
                        swap(a[m], a[r--]);
                    } else {
                        if (mp[1] > m) {
                            ans.push_back({m, mp[1]});
                            swap(a[m], a[mp[1]]);
                            ans.push_back({m, r});
                            swap(a[m], a[r]);
                            mp[1] = r;
                        } else {
                            ans.push_back({l, r});
                            swap(a[l++], a[r]);
                        }
                    }
                } else r--;
            }
        }
    cout << ans.size() << '\n';
    for (auto& x : ans) cout << x.f << ' ' << x.s << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}

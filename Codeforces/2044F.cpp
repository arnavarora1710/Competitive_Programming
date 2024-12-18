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
typedef priority_queue<int, vi, greater<int>> pqmn;

const int N = 2e6 + 5, inf = 1e18, mod = 1e9 + 7;
const double PI = acos(-1), EPS = 1e-9;
int n, m, k, q, x, y, u, v, a[N], b[N];

void solve() {
    cin >> n >> m >> q;
    rep(i,1,n) cin >> a[i];
    rep(i,1,m) cin >> b[i];
    unordered_map<int, bool> cnta, cntb;
    rep(i,1,n) cnta[a[i]] = true;
    rep(i,1,m) cntb[b[i]] = true;
    int sa = 0, sb = 0;
    rep(i,1,n) sa += a[i];
    rep(i,1,m) sb += b[i];
    int s = sa*sb;
    auto check = [&] (int f1, int f2) {
        int xx = sa - f1;
        int yy = sb - f2;
        if (cnta[xx] and cntb[yy]) {
            cout << "YES\n";
            return 1;
        }
        return 0;
    };
    rep(j,1,q) {
        cin >> x;
        int tot = x;
        int sgn = tot >= 0 ? 1 : -1;
        if (!tot) {
            if (cnta[sa] or cntb[sb]) cout << "YES\n";
            else cout << "NO\n";
            goto done;
        }
        tot = abs(tot);
        for (int i = 1; i * i <= tot; ++i) {
            if (tot % i == 0) {
                int f1 = i, f2 = tot/i;
                if (sgn == 1) {
                    if (check(f1, f2)) goto done;
                    if (check(-f1, -f2)) goto done;
                    if (check(f2, f1)) goto done;
                    if (check(-f2, -f1)) goto done;
                } else {
                    if (check(f1, -f2)) goto done;
                    if (check(-f1, f2)) goto done;
                    if (check(f2, -f1)) goto done;
                    if (check(-f2, f1)) goto done;
                }
            }
        }
        cout << "NO\n";
        done:;
    }
}

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}

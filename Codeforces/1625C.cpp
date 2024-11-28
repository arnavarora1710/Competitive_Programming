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
typedef priority_queue<int, vi, greater<int>> pqmn;

const int N = 505, inf = 1e18, mod = 1e9 + 7;
const double PI = acos(-1), EPS = 1e-9;
int n, l, k, q, x, y, u, v, a[N], d[N];

void solve() {
    cin >> n >> l >> k;
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) cin >> d[i];
    a[++n] = l, d[n] = 0;
    vii dp(n+1, vi(k+1,inf));
    dp[1][0] = 0;
    rep(i,2,n) dp[i][0] = dp[i-1][0] + d[i-1] * (a[i] - a[i-1]);
    rep(i,1,n) {
        rep(j,0,k) {
            if (dp[i][j] == inf) continue;
            rep(p,i+1,n)
                if (j+p-i-1 <= k)
                    dp[p][j+p-i-1] = min(dp[p][j+p-i-1], dp[i][j] + d[i] * (a[p] - a[i]));
        }
    }
    int ans = inf;
    rep(i,0,k) ans = min(ans, dp[n][i]);
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}

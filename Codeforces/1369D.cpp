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
int n, k, q, x, y, u, v, dp[N][2];

void solve() {
    cin >> n;
    cout << (max(dp[n][0], dp[n][1]) * 4)%mod << '\n';
}

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    dp[3][1] = dp[4][0] = dp[4][1] = 1;
    rep(i,5,2e6+3) {
        int d1 = max(dp[i-1][0], dp[i-1][1]);
        int d2 = max(dp[i-2][0], dp[i-2][1]);
        int d3 = max(dp[i-3][0], dp[i-3][1]);
        int d4 = max(dp[i-4][0], dp[i-4][1]);
        dp[i][0] = ((d2*2)%mod + d1)%mod;
        dp[i][1] = ((1 + (d3*4)%mod + (d4*4)%mod)%mod + d2)%mod;
    }

    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}

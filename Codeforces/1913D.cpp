// http://codeforces.com/contest/1913/problem/D
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

const int N = 2e6 + 5, inf = 1e18, mod = 998244353;
const double PI = acos(-1), EPS = 1e-9;
int n, k, q, x, y, u, v, a[N];

void solve() {
    cin >> n; a[0] = -inf;
    rep(i, 1, n) cin >> a[i];
    stack<pi> st;
    vi vis(n + 1);
    repr(i, n, 1) {
        while (!st.empty() && st.top().f >= a[i])
            st.pop();
        vis[i] = st.empty();
        st.push({a[i], i});
    }
    vi dp(n + 1), pdp(n + 1);
    dp[0] = pdp[0] = 1;
    // dp[1] = 1; pdp[1] = 2;
    while (!st.empty()) st.pop();
    st.push({0, 1});
    int ans = 0;
    rep(i, 1, n) {
        while (!st.empty() && a[st.top().f] >= a[i])
            st.pop();
        int cur = (st.empty() ? 0 : st.top().s);
        int index = (st.empty() ? 0 : st.top().f) + 1;
        dp[i] = (cur + (pdp[i - 1] - pdp[index - 1] + mod) % mod) % mod;
        // if (!dp[i]) dp[i]++;
        // cerr << index << ' ' << cur << ' ' << dp[i] << '\n';
        // cerr << dp[i] << ' ';
        pdp[i] = (pdp[i - 1] + dp[i]) % mod;
        if (vis[i]) ans = (ans + dp[i]) % mod;
        if (st.size() == 1) st.push({i, (cur + dp[i] + mod - 1) % mod});
        else st.push({i, (cur + dp[i]) % mod});
    }
    cout << ans << '\n';
}
// 5 1
// 1

// 5 1 4 2
// 5 1 2
// 1 4 2
// 1 2

// 5 1 4 2 3
// 5 1 2 3
// 1 4 2 3
// 1 2 3
// 5 1 3
// 1 3

// 2 1 3
// 1 3
// 2 1
// 1

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}
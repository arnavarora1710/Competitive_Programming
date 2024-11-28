// http://codeforces.com/contest/2039/problem/C1
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
    int x, m; cin >> x >> m;
    int lg = log2(x);
    int bd = (1 << (lg+1));
    bd = min(bd, m);
    int ans = 0;
    int l = 1, r = m/x+1;
    // bug(l, r);
    while (r - l > 1) {
        int mid = l + (r - l) / 2;
        int val = ((x * mid) ^ x);
        // bug(mid, x, val);
        if (val <= m) l = mid;
        else r = mid;
    }
    bug(l);
    int lg1 = log2(m);
    lg1++;
    ans += l - 1 + (1<<lg1) / x - (m-1)/x;
    bug(ans, ((1<<lg1))/ x - (m-1)/x, 1<<lg1);
    // int k=0;
    // while ((x^(x<<(k+1))) <= m)
    //     k++;
    // ans += (1<<k);

    // int l = (1<<k), r = (1<<k)+1e9;
    // while (r-l>1) {
    //     int mid = l+(r-l)/2;
    //     int v = (x^(x*mid));
    //     if (v <= m) l=mid;
    //     else r=mid;
    // }
    // ans+=l-(1<<k);
    // for (int i = (1<<k)+1; ; ++i) {
    //     int v = ((x*i) ^ x);
    //     bug(i, x, v);
    //     if (v > 0 and v <= m) ans++;
    //     else if (x*i > m) break;
    // }
    rep(i,1,bd) {
        // int v = x^i;
        // if (v%i==0) ans++;
        for (int j = 2 * i; j <= bd; j += i) {
            if ((j ^ i) == x) ans++;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}

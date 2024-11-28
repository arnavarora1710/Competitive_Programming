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
    int l, r, i, k;
    cin >> l >> r >> i >> k;
    auto xorr = [&] (int x) {
        int m = x % 4;
        if (m == 0) return x;
        else if (m == 1) return 1LL;
        else if (m == 2) return x + 1;
        else return 0LL;
    };
    int range = xorr(l - 1) ^ xorr(r);
    // 28 = 11100
    // 00111, 01111, 10111
    int pw = (1LL << i);
    int diffL = ((k % pw) - (l % pw) + pw) % pw;
    int diffR = ((r % pw) - (k % pw) + pw) % pw;
    l += diffL; r -= diffR;
    l >>= i, r >>= i;
    int extra = 0;
    if ((r - l + 1) % 2 != 0) extra = k;
    l = xorr(r) ^ xorr(l - 1);
    l <<= i;
    cout << (range ^ l ^ extra) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}

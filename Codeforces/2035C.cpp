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

const int N = 2e6 + 5, inf = 1e18, mod = 1e9 + 7;
const double PI = acos(-1), EPS = 1e-9;
int n, k, q, x, y, u, v;

void solve() {
    cin >> n; vi a(n + 1), b(n + 1);
    rep(i, 1, n) a[i] = i, b[i] = i;
    a.erase(a.begin() + 1);
    a.erase(a.begin() + 2);
    int bk = a.back();
    a.pop_back();
    int bk1 = a.back();
    a.pop_back();
    int bk2 = 0;
    if (n % 2 == 0) {
        bk2 = a.back();
        a.pop_back();
    }
    a.push_back(1);
    a.push_back(3);
    if (n % 2 == 0) {
        a.push_back(bk2);
    }
    a.push_back(bk1);
    a.push_back(bk);
    int lg = log2(n);
    b.erase(b.begin() + (1 << lg) - 1);
    swap(b[n], b[n - 1]);
    b.push_back((1 << lg) - 1);
    int k = 0, k1 = 0;
    rep(i, 1, n) {
        if (i&1) k &= a[i];
        else k |= a[i];
        if (i&1) k1 &= b[i];
        else k1 |= b[i];
    }
    if (k > k1) {
        cout << k << '\n';
        rep(i, 1, n) cout << a[i] << ' ';
        cout << '\n';
    } else {
        cout << k1 << '\n';
        rep(i, 1, n) cout << b[i] << ' ';
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}

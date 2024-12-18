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

const int N = 2e6 + 5, inf = 1e18, mod = 1e9 + 7;
const double PI = acos(-1), EPS = 1e-9;
int n, k, q, x, y, u, v, a[N];

int ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int x; cin >> x;
    return x;
}

void submit(int x) {
    cout << "! " << x << endl;
}

void solve() {
    cin >> n;
    int smx = ask(1, n);
    int l = 0, r = smx;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (ask(m, smx) == smx) l = m;
        else r = m;
    }
    if (!l) {
        l = smx, r = n;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (ask(smx, m) != smx) l = m;
            else r = m;
        }
        submit(r);
    } else submit(l);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}
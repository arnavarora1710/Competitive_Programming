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
int n, k, q, x, y, u, v, a[N];

struct seg {
    vector<int> tr;

    seg(int n) {
        tr.assign(4*n+1, 0);
    }

    int rmq(int v, int ll, int rr, int l, int r) {
        if (l > r) return 0;
        else if (l == ll && r == rr) return tr[v];
        else {
            int mm = ll + (rr - ll) / 2;
            int left = rmq(v<<1, ll, mm, l, min(mm, r));
            int right = rmq(v<<1|1, mm + 1, rr, max(mm + 1, l), r);
            return gcd(left, right);
        }
    }

    void update(int v, int ll, int rr, int val, int l, int r) {
        if (l > r) return;
        else if (l == ll and r == rr) tr[v] = val;
        else {
            int mm = ll + (rr - ll) / 2;
            update(v<<1, ll, mm, val, l, min(mm, r));
            update(v<<1|1, mm + 1, rr, val, max(mm + 1, l), r);
            tr[v] = gcd(tr[v<<1], tr[v<<1|1]);
        }
    }
};

void solve() {
    cin >> n;
    rep(i,0,n-1) cin >> a[i];
    seg tree = *(new seg(n));
    rep(i,0,n-1) tree.update(1, 0, n - 1, a[i], i, i);
    // bug(tree.rmq(1,0,n-1,0,n-1));
    auto check = [&] (int m) {
        // bug(m);
        set<int> s;
        rep(i,0,n-1) {
            int j = i+m-1;
            int g;
            if (j >= n) {
                g = gcd(tree.rmq(1,0,n-1,i,n-1), tree.rmq(1,0,n-1,0,j-n));
            }
            else g = tree.rmq(1,0,n-1,i,j);
            // bug(i, j, g);
            s.insert(g);
        }
        return s.size() == 1;
    };
    int l = 0, r = n+1;
    while (r-l>1) {
        int m = l+(r-l)/2;
        if (!check(m)) l = m;
        else r = m;
    }
    cout << l << '\n';
}

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}

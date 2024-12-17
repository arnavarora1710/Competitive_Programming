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
double c, m, p, v, ans;

void f(vector<double>& a, double prob, int len, int cur) {
    if (cur == -1) {
        prob *= a[2];
        double mul = prob * (len + 1);
        ans += mul;
        // if (mul > EPS) bug(prob, len, cur);
        // if (mul > EPS) ans += mul;
        return;
    }
    vector<double> old = a;
    if (cur) {
        if (a[0] < EPS) return;
        prob *= a[0];
        if (a[0] > v) {
            a[0] -= v;
            if (a[1] > EPS)
                a[1] += v/2.0, a[2] += v/2.0;
            else
                a[2] += v;
        }
        else {
            double rem = a[0];
            a[0] = 0;
            if (a[1] > EPS)
                a[1] += rem/2.0, a[2] += rem/2.0;
            else
                a[2] += rem;
        }
    } else {
        if (a[1] < EPS) return;
        prob *= a[1];
        if (a[1] > v) {
            a[1] -= v;
            if (a[0] > EPS)
                a[0] += v/2.0, a[2] += v/2.0;
            else
                a[2] += v;
        }
        else {
            double rem = a[1];
            a[1] = 0;
            if (a[0] > EPS)
                a[0] += rem/2.0, a[2] += rem/2.0;
            else
                a[2] += rem;
        }
    }
    f(a, prob, len+1, cur);
    f(a, prob, len+1, !cur);
    f(a, prob, len+1, -1);
    a = old;
}

void solve() {
    cin >> c >> m >> p >> v;
    ans = 0;
    vector<double> a = {c, m, p};
    f(a, 1, 0, 0);
    f(a, 1, 0, 1);
    f(a, 1, 0, -1);
    cout << fixed << setprecision(18) << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}

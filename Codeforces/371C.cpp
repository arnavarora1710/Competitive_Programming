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

void solve() {
    string s; cin >> s;
    int nb, ns, nc; cin >> nb >> ns >> nc;
    int pb, ps, pc; cin >> pb >> ps >> pc;
    int r; cin >> r;
    map<char, int> mp;
    for (char c : s) mp[c]++;
    int ndb = mp['B'], nds = mp['S'], ndc = mp['C'];
    int alr = 0;
    if (not ndb) nb = 0;
    if (not nds) ns = 0;
    if (not ndc) nc = 0;
    while (1) {
        vi forAlrPlus1 = {ndb, nds, ndc};
        vi tmp = forAlrPlus1;
        rep(i,0,2) tmp[i] *= alr;
        int farB = tmp[0] - nb;
        int farS = tmp[1] - ns;
        int farC = tmp[2] - nc;
        int fb = farB, fs = farS, fc = farC;
        rep(i,0,2) forAlrPlus1[i] *= alr + 1;
        farB = forAlrPlus1[0] - nb;
        farS = forAlrPlus1[1] - ns;
        farC = forAlrPlus1[2] - nc;
        farB = max(0LL, farB);
        farS = max(0LL, farS);
        farC = max(0LL, farC);
        int priceB = farB * pb, priceS = farS * ps, priceC = farC * pc;
        if (r < priceB + priceS + priceC) {
            cout << alr;
            return;
        }
        alr++;
        nb += farB, ns += farS, nc += farC;
        r -= priceB + priceS + priceC;
        if (fb == 0 and fs == 0 and fc == 0) break;
    }
    int tot = pb * ndb + ps * nds + pc * ndc;
    alr += r / tot;
    cout << alr;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}

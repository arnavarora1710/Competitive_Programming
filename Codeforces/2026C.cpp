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
string s;

void solve() {
    cin >> n >> s;
    s = "$" + s;
    int ans = (n * (n + 1)) / 2;
    map<char, deque<int>> mp; rep(i,1,n) mp[s[i]].push_back(i);
    repr(i,n,1) {
        if (s[i] == '1' and !mp['1'].empty() and mp['1'].back() == i) {
            if (!mp['0'].empty()) {
                ans -= mp['1'].back();
                mp['1'].pop_back();
                mp['0'].pop_back();
            } else if (mp['1'].size() >= 2) {
                ans -= mp['1'].back();
                mp['1'].pop_back();
                mp['1'].pop_front();
            }
        } else if (s[i] == '0' and !mp['0'].empty() and mp['0'].back() == i) mp['0'].pop_back();
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}

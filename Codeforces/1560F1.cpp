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
int k, q, x, y, u, v, a[N];
string n;
string ans;

void f(int i, int num1, int num2, bool abv, string& cur) {
    if (i == n.size()) {
        if (ans.empty() or ans > cur) ans = cur;
        return;
    }
    if (num2 == -1) {
        int lb = (abv ? 0 : n[i] - '0');
        rep(j,lb,9) {
            if (j == num1) {
                cur += j + '0';
                bool tmp = abv;
                if (j > n[i] - '0') tmp = 1;
                f(i+1, num1, num2, tmp, cur);
                cur.pop_back();
            } else {
                cur += j + '0';
                bool tmp = abv;
                if (j > n[i] - '0') tmp = 1;
                f(i+1, num1, j, tmp, cur);
                cur.pop_back();
            }
        }
    } else {
        if (abv or num1 >= n[i] - '0') {
            cur += num1 + '0';
            f(i+1, num1, num2, abv or num1 > n[i] - '0', cur);
            cur.pop_back();
        }
        if (abv or num2 >= n[i] - '0') {
            cur += num2 + '0';
            f(i+1, num1, num2, abv or num2 > n[i] - '0', cur);
            cur.pop_back();
        }
    }
}

void solve() {
    cin >> n >> k; ans.clear();
    int sz = n.size();
    string t(sz, n[0]);
    string tt(sz, n[0] + 1);
    if (k == 1) {
        cout << (stoll(t) >= stoll(n) ? t : tt) << '\n';
    } else {
        string cur;
        cur += n[0];
        f(1,n[0]-'0',-1,0,cur);
        cout << ans << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}

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
    auto chk = [&] (string t) {
        string ot = t;
        reverse(t.begin(), t.end());
        return t == ot;
    };
    int cnt = 0;
    for (auto& c : s) cnt += (c == '0');
    if (chk(s)) {
        if (cnt == 1 || !(cnt&1)) cout << "BOB\n";
        else cout << "ALICE\n";
    } else {
        int i = 0, j = n - 1;
        int c[2] = {0};
        while (i <= j) {
            int v1 = s[i] - '0', v2 = s[j] - '0';
            c[v1 ^ v2]++;
            if (v1^v2) s[i] = s[j] = '1';
            i++, j--;
        }
        int alice = 0, bob = c[1];
        cnt = 0;
        for (auto& ch : s) cnt += (ch == '0');
        if (cnt) {
            if (cnt == 1) {
                alice++;
            } else {
                bob++;
            }
        }
        if (bob == alice) cout << "DRAW\n";
        else if (bob > alice) cout << "ALICE\n";
        else cout << "BOB\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}

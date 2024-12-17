// http://codeforces.com/contest/2034/problem/C
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
int n, m, k, q, x, y, u, v;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
map<char, int> mp;
int ans;

void solve() {
    cin >> n >> m; ans = 0;
    vector<vector<char>> a(n+2, vector<char>(m+2, '$'));
    rep(i,1,n) {
        rep(j,1,m) cin >> a[i][j];
    }
    vii b(n+2, vi(m+2,1));
    queue<pi> q;
    q.push({0,0});
    b[0][0] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        rep(k,0,3) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 and ny >= 0 and nx <= n + 1 and ny <= m + 1) {
                // bug(x, y, nx, ny, a[nx][ny]);
                if ((a[nx][ny] == '$' or (a[nx][ny] != '?' and mp[a[nx][ny]] == k)) and b[nx][ny]) {
                    b[nx][ny] = 0;
                    q.push({nx, ny});
                }            
            }
        }
    }
    rep(i,1,n) {
        rep(j,1,m) {
            if (a[i][j] == '?') {
                bool ok = 0;
                rep(k,0,3) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (b[ni][nj]) {
                        ok = 1;
                        break;
                    }
                }
                if (!ok) b[i][j] = 0;
            }
            ans += b[i][j];
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    mp['D'] = 0, mp['R'] = 1, mp['U'] = 2, mp['L'] = 3;
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}

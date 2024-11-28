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
typedef priority_queue<vi, vii, greater<vi>> pqmn;

const int N = 35, inf = 1e18, mod = 1e9 + 7;
const double PI = acos(-1), EPS = 1e-9;
int n, k, q, x, y, u, v;
char a[N][N];
int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};

void solve() {
    int n, m;
    while (cin >> n >> m) {
        if (!n) break;
        swap(n, m);
        rep(i,1,n) rep(j,1,m) cin >> a[i][j];

        int sx, sy;
        rep(i,1,n) rep(j,1,m)
            if (a[i][j] == 'S') sx = i, sy = j;

        vii d(n + 1, vi(m + 1, inf));
        pqmn pq;
        pq.push({0, sx, sy});
        d[sx][sy] = 0;

        auto check = [&] (int i, int j) {
            return i > 0 and j > 0 and i <= n and j <= m and a[i][j] != 'X';
        };

        while (!pq.empty()){
            auto tp = pq.top(); pq.pop();
            if (a[tp[1]][tp[2]] == 'D') {
                cout << tp[0] << '\n';
                break;
            }
            rep(i,0,3) {
                int x = tp[1] + dx[i], y = tp[2] + dy[i];
                if (check(x, y)) {
                    int weight = d[tp[1]][tp[2]] + (a[x][y] == 'D' ? 0 : a[x][y] - '0');
                    if (d[x][y] > weight) {
                        d[x][y] = weight;
                        pq.push({d[x][y], x, y});
                    }
                }
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q = 1; if (MULTI_TEST) cin >> Q;
    while (Q--) solve();
}

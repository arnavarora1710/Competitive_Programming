// https://codeforces.com/contest/580/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
int n, m, x, y, ans;
set<int> cats;
vector<int> adj[maxn];

void dfs(int nn, int pp, int xx) {
    if (nn != 1 && adj[nn].size() == 1) ans++;
    for (int cc : adj[nn]) {
        if (cc != pp) {
            int new_xx = xx;
            if (cats.find(cc) != cats.end()) new_xx++;
            else new_xx = 0;
            if (new_xx <= m) dfs(cc, nn, new_xx);
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (x) cats.insert(i);
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, -1, cats.find(1) != cats.end());
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
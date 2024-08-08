// https://codeforces.com/contest/1997/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, a[maxn], mn[maxn];
vector<int> adj[maxn];

void dfs(int nn, int pp) {
    for (auto& cc : adj[nn]) {
        if (cc != pp) {
            dfs(cc, nn);
            mn[nn] = min(mn[nn], min(a[cc], mn[cc]));
        }
    }
    if (nn != 1 && mn[nn] != inf && mn[nn] > a[nn])
        a[nn] = (a[nn] + mn[nn]) / 2;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) adj[i].clear();
    for (int i = 2; i <= n; ++i) {
        int p; cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    for (int i = 1; i <= n; ++i) mn[i] = inf;
    dfs(1, -1);
    cout << a[1] + mn[1] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

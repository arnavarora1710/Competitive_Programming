// https://codeforces.com/contest/1702/problem/E
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, cnt[maxn];
bool vis[maxn];
pi a[maxn];
vector<int> adj[maxn];

int dfs(int nn) {
    vis[nn] = true;
    for (int cc : adj[nn]) {
        if (!vis[cc]) {
            return dfs(cc) + 1;
        }
    }
    return 1;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cnt[i] = 0;
        vis[i] = false;
        adj[i].clear();
    }
    for (int i = 0; i < n; ++i) cin >> a[i].f >> a[i].s; 
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        if (a[i].f == a[i].s) { 
            flag = true;
            goto done;
        }
        adj[a[i].f].push_back(a[i].s);
        adj[a[i].s].push_back(a[i].f);
        cnt[a[i].f]++, cnt[a[i].s]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] != 2) { 
            flag = true;
            goto done;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            if (dfs(i)&1) {
                flag = true;
                goto done;
            }
        }
    }
    done:
        cout << (flag ? "NO\n" : "YES\n");
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

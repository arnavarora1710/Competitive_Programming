// https://codeforces.com/contest/1775/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 3e5 + 5, maxm = 2 * maxn + 5, inf = 1e18;
int n, s, t, a[maxn];
bool vis[maxm];
vector<int> adj[maxm];

vector<int> spf(maxn + 1, 1);

void sieve() {
    spf[0] = 0;
    for (int i = 2; i <= maxn; i++) {
        if (spf[i] == 1) {
            for (int j = i; j <= maxn; j += i) {
                if (spf[j]== 1)
                    spf[j] = i;
            }
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> s >> t;
    s--, t--;

    vector<int> p(maxm, -1);

    for (int i = 0; i < n; ++i) {
        while (a[i] != 1) {
            adj[i].push_back(maxn + spf[a[i]]);
            adj[maxn + spf[a[i]]].push_back(i);
            a[i] = a[i] / spf[a[i]];
        }
    }

    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int& v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                p[v] = u;
                q.push(v);
            }
        }
    }

    vector<int> ans;
    int st = t;
    while (st != s) {
        if (st == -1) {
            cout << -1 << '\n';
            return;
        }
        if (st <= maxn) ans.push_back(st + 1);
        st = p[st];
    }
    ans.push_back(s + 1);
    reverse(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (int& node : ans) cout << node << ' ';
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sieve();
    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

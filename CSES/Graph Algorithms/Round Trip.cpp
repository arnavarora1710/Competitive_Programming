#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1;
int n, m, a, b; vector<int> ans, adj[MAXN]; 
int flag, ender, vis[MAXN], par[MAXN];

void dfs(int start, int parent) {
    if (vis[start]) return;
    vis[start] = 1;
    for (int node : adj[start]) {
        if (!vis[node]) {
            par[node] = start; dfs(node, start); vis[node] = 2;
            if (flag) break;
        }
        else if (node != parent && vis[node] == 1) {
            flag = start; ender = node; return;
        }
    }
    vis[start] = 2;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b; adj[a].push_back(b); adj[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) if (!vis[i]) dfs(i, -1);
    if (!flag) cout << "IMPOSSIBLE\n";
    else {
        ans.push_back(ender);
        while (flag != ender) ans.push_back(flag), flag = par[flag];
        ans.push_back(ender);
        cout << ans.size() << endl;
        for (int node : ans) cout << node << " ";
    }
    return 0;
}
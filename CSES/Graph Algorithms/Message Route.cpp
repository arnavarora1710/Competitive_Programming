#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1;
int n, m, a, b; vector<int> adj[MAXN]; 
bool vis[MAXN]; int dist[MAXN], prevNode[MAXN];

int main() {
    cin >> n >> m; for (int i = 2; i <= n; ++i) dist[i] = 1e9;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b; adj[a].push_back(b); adj[b].push_back(a);
    }
    queue<int> q; q.push(1); vis[1] = true;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                vis[neighbor] = true;
                dist[neighbor] = dist[node] + 1;
                prevNode[neighbor] = node;
                q.push(neighbor);
            }
        }
    }
    if (dist[n] == 1e9) {
        cout << "IMPOSSIBLE";
    } else {
        cout << dist[n] + 1 << endl;
        int node = n; vector<int> ans;
        while (node) ans.push_back(node), node = prevNode[node];
        reverse(ans.begin(), ans.end());
        for (auto& el : ans) cout << el << " ";
    }
    return 0;
}
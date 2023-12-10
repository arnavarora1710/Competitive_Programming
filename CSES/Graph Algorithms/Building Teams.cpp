#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1;
int n, m, a, b; vector<int> adj[MAXN];
bool vis[MAXN]; int coloring[MAXN];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b; adj[a].push_back(b); adj[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            queue<int> q; q.push(i); vis[i] = true; 
            coloring[i] = 1;
            while (!q.empty()) {
                int node = q.front(); q.pop();
                for (int neighbor : adj[node]) {
                    if (!vis[neighbor]) {
                        vis[neighbor] = true;
                        (coloring[node] == 1 ? coloring[neighbor] = 2 : coloring[neighbor] = 1);
                        q.push(neighbor);
                    } else {
                        int orig = coloring[neighbor];
                        (coloring[node] == 1 ? coloring[neighbor] = 2 : coloring[neighbor] = 1);
                        if (orig != coloring[neighbor]) {
                            cout << "IMPOSSIBLE"; return 0;
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) cout << coloring[i] << " ";
    return 0;
}
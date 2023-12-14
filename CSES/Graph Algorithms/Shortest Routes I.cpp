#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, int> pi;
const int MAXN = 1e5 + 1;
int n, m, a, b, c; 
long long dist[MAXN]; bool vis[MAXN];
vector<pair<int, int>> adj[MAXN];

int main() {
    cin >> n >> m; for (int i = 2; i <= n; ++i) dist[i] = LLONG_MAX;
    for (int i = 0; i < m; ++i) cin >> a >> b >> c, adj[a].push_back({b, c});
    priority_queue<pi, vector<pi>, greater<pi>> pq; pq.push({0, 1});
    while (!pq.empty()) {
        pi tp = pq.top(); pq.pop();
        int start = tp.second;
        if (vis[start]) continue;
        vis[start] = true;
        for (auto& neighbor : adj[start]) {
            int node = neighbor.first;
            long long weight = neighbor.second;
            if (weight + dist[start] < dist[node]) {
                dist[node] = weight + dist[start];
                pq.push({dist[node], node});
            }
        }
    }
    for (int i = 1; i <= n; ++i) cout << dist[i] << " ";
    return 0;
}
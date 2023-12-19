#include <bits/stdc++.h>
using namespace std;
const int MAXN = 501;
const long long INF = 1e12;
int n, m, a, b, q; long long c, adj[MAXN][MAXN];
 
void floydWarshall() {
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}
 
int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) adj[i][j] = INF;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        adj[a][a] = adj[b][b] = 0;
        adj[a][b] = min(adj[a][b], c);
        adj[b][a] = min(adj[b][a], c);
    }
    floydWarshall();
    for (int i = 0; i < q; ++i) {
        cin >> a >> b; cout << (adj[a][b] >= INF ? -1 : adj[a][b]) << endl;
    }
    return 0;
}
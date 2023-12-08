#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
int n, m, dx[] = {-1, 0, 1}, dy[] = {-1, 0, 1};
string a[MAXN]; bool vis[MAXN][MAXN]; vector<pair<int, int>> idx;

bool isValid(int x, int y) {
    return (x >= 0) && (y >= 0) && (x < n) && (y < m);
}

void dfs(int x, int y) {
    if (!isValid(x, y) || vis[x][y] || a[x][y] == '#') return;
    vis[x][y] = true;
    for (int xdir : dx)
        for (int ydir : dy) 
            if (!xdir || !ydir) dfs(x + xdir, y + ydir);
}

int main() {
    cin >> n >> m; 
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == '.') idx.push_back({i, j});
        }
    int ans = 0;
    for (auto& pair : idx) {
        int x = pair.first, y = pair.second;
        if (!vis[x][y]) dfs(x, y), ans++;
    }
    cout << ans;
    return 0;
}
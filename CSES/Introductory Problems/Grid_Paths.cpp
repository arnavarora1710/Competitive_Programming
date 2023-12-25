#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <iostream> 
#include <unordered_map>
using namespace std;

string a; 
unordered_map<char, int> m; 
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int p[48]; bool vis[9][9]; 
 
int rec(int x, int y, int path) {
    
    if (vis[x][y - 1] && vis[x][y + 1] && !vis[x - 1][y] && !vis[x + 1][y])
        return 0;
    if (!vis[x][y - 1] && !vis[x][y + 1] && vis[x - 1][y] && vis[x + 1][y])
        return 0;

    if (x == 7 && y == 1) return path == 48;
    else if (path == 48) return 0;

    vis[x][y] = true;
    int ret = 0; 

    if (p[path] == 4) {
        if (!vis[x - 1][y]) ret += rec(x - 1, y, path + 1);
        if (!vis[x][y + 1]) ret += rec(x, y + 1, path + 1);
        if (!vis[x + 1][y]) ret += rec(x + 1, y, path + 1);
        if (!vis[x][y - 1]) ret += rec(x, y - 1, path + 1);
    }
    else {
        int xx = x + dx[p[path]], yy = y + dy[p[path]];
        if (!vis[xx][yy]) ret += rec(xx, yy, path + 1);
    }

    vis[x][y] = false;
    return ret;
}
 
void solve() {
    cin >> a;

    m['U'] = 0, m['R'] = 1, m['D'] = 2, m['L'] = 3, m['?'] = 4;

    for (int i = 0; i < 9; ++i) vis[0][i] = vis[i][0] = vis[8][i] = vis[i][8] = true;

    for (int i = 0; i < 48; ++i) p[i] = m[a[i]];

    cout << rec(1, 1, 0) << endl;
}
 
signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
 
    solve();
 
    return 0;
}
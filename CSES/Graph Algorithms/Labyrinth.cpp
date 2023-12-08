#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
int n, m; pair<int, int> start, ended; string ans;

bool vis[MAXN][MAXN]; char a[MAXN][MAXN]; int prevStep[MAXN][MAXN];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
string steps = "URDL";

bool isValid(int x, int y) {
    return (x >= 0) && (y >= 0) && (x < n) && (y < m) && a[x][y] != '#' && !vis[x][y];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'A') start = {i, j};
            else if (a[i][j] == 'B') ended = {i, j};
        }
    queue<pair<int, int>> q; q.push(start);
    vis[start.first][start.second] = true;
    while (!q.empty()) {
        pair<int, int> front = q.front(); q.pop();
        int x = front.first, y = front.second;
        for (int i = 0; i < 4; ++i) {
            int xdir = dx[i], ydir = dy[i];
            if (isValid(x + xdir, y + ydir)) {
                vis[x + xdir][y + ydir] = true;
                prevStep[x + xdir][y + ydir] = i;
                q.push({x + xdir, y + ydir});
            }
        }
    }
    if (vis[ended.first][ended.second]) {
        cout << "YES\n";
        while (ended != start) {
            int x = ended.first, y = ended.second;
            int curr = prevStep[x][y];
            ans.push_back(steps[curr]);
            ended = {x - dx[curr], y - dy[curr]};
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl << ans;
    }
    else cout << "NO";
    return 0;
}
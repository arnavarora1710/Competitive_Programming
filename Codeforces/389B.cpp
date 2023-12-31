// https://codeforces.com/problemset/problem/389/B
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
int n; char a[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
set<pair<int, int>> done;

bool valid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < n;
}

void can(int i, int j) {
    for (int d = 0; d < 4; ++d) {
            int xx = i + dx[d], yy = j + dy[d];
            if (valid(xx, yy) && !done.count({xx, yy}) && a[xx][yy] == '#') continue;
            else return;
    }
    done.insert({i, j});
    for (int d = 0; d < 4; ++d) done.insert({i + dx[d], j + dy[d]});
}

void solve() {
    cin >> n; int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (a[i][j] == '#') cnt++;
        }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (done.count({i, j})) continue;
            can(i, j);
        }
    }
    int sz = done.size();
    cout << (sz == cnt ? "YES" : "NO");
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
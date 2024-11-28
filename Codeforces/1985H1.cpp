// https://codeforces.com/contest/1985/problem/H1
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, m;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

bool isValid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

void solve() {
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) cin >> a[i][j];
    vector<vector<int>> comp(n, vector<int>(m, -1));
    int color = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (comp[i][j] == -1 && a[i][j] == '#') {
                queue<pi> q;
                q.push({i, j});
                comp[i][j] = color;
                while (!q.empty()) {
                    pi tp = q.front(); q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int x = tp.f + dx[k], y = tp.s + dy[k];
                        if (isValid(x, y) && comp[x][y] == -1 && a[x][y] == '#') {
                            comp[x][y] = color;
                            q.push({x, y});
                        }
                    }
                }
                color++;
            }
        }
    }
    map<int, int> cnt, unique_colors;
    vector<pi> row(n), col(m);
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        unique_colors.clear();
        for (int j = 0; j < m; ++j) 
            if (comp[i][j] != -1) unique_colors[comp[i][j]]++;
        vector<int> x;
        for (auto& v : cnt) 
            if (!unique_colors.count(v.f)) x.push_back(v.f);
        for (auto& xx : x) cnt.erase(xx);
        for (auto& v : unique_colors) cnt[v.f] += v.s;
        for (auto& v : cnt) sum += v.s;
        row[i].f = sum;
    }
    cnt.clear();
    for (int i = n - 1; i >= 0; --i) {
        int sum = 0;
        unique_colors.clear();
        for (int j = 0; j < m; ++j) 
            if (comp[i][j] != -1) unique_colors[comp[i][j]]++;
        vector<int> x;
        for (auto& v : cnt) 
            if (!unique_colors.count(v.f)) x.push_back(v.f);
        for (auto& xx : x) cnt.erase(xx);
        for (auto& v : unique_colors) cnt[v.f] += v.s;
        for (auto& v : cnt) sum += v.s;
        row[i].s = sum;
    }
    cnt.clear();
    for (int j = 0; j < m; ++j) {
        int sum = 0;
        unique_colors.clear();
        for (int i = 0; i < n; ++i) 
            if (comp[i][j] != -1) unique_colors[comp[i][j]]++;
        vector<int> x;
        for (auto& v : cnt)
            if (!unique_colors.count(v.f)) x.push_back(v.f);
        for (auto& xx : x) cnt.erase(xx);
        for (auto& v : unique_colors) cnt[v.f] += v.s;
        for (auto& v : cnt) sum += v.s;
        col[j].f = sum;
    }
    cnt.clear();
    for (int j = m - 1; j >= 0; --j) {
        int sum = 0;
        unique_colors.clear();
        for (int i = 0; i < n; ++i) 
            if (comp[i][j] != -1) unique_colors[comp[i][j]]++;
        vector<int> x;
        for (auto& v : cnt)
            if (!unique_colors.count(v.f)) x.push_back(v.f);
        for (auto& xx : x) cnt.erase(xx);
        for (auto& v : unique_colors) cnt[v.f] += v.s;
        for (auto& v : cnt) sum += v.s;
        col[j].s = sum;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int up = (i ? row[i - 1].f : 0);
        int down = (i + 1 < n ? row[i + 1].s : 0);
        ans = max(ans, m + up + down);
    }
    for (int i = 0; i < m; ++i) {
        int left = (i ? col[i - 1].f : 0);
        int right = (i + 1 < m ? col[i + 1].s : 0);
        ans = max(ans, n + left + right);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

// https://codeforces.com/contest/1731/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int inf = 1e18;
int n, m;
vector<vector<int>> a;

bool check(int mid) {
    vector<vector<int>> b(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) 
            if (a[i][j] < mid) b[i][j] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int num1 = (i ? b[i - 1][j] : 0);
            int num2 = (j ? b[i][j - 1] : 0);
            int num3 = (i && j ? b[i - 1][j - 1] : 0);
            b[i][j] += num1 + num2 - num3;
        }
    }
    for (int i = mid - 1; i < n; ++i) {
        for (int j = mid - 1; j < m; ++j) {
            int ux = i - mid + 1, uy = j - mid + 1;
            int dx = i, dy = j;
            int tot = b[dx][dy];
            int sub1 = (ux ? b[ux - 1][dy] : 0);
            int sub2 = (uy ? b[dx][uy - 1] : 0);
            int add = (ux && uy ? b[ux - 1][uy - 1] : 0);
            int ans = tot - sub1 - sub2 + add;
            if (!ans) return true;
        }
    }
    return false;
    
}

void solve() {
    cin >> n >> m;

    a.clear(); a.resize(n);
    for (int i = 0; i < n; ++i) {
        a[i].resize(m);
        for (int j = 0; j < m; ++j) cin >> a[i][j];
    }

    int l = 0, r = 1e3 + 1;
    while (r - l > 1) {
        int mid = l + (r - l) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
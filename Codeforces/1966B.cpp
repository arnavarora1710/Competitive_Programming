// https://codeforces.com/contest/1966/problem/B
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 505, inf = 1e18;
int n, m;
char a[maxn][maxn];

bool can(int i, int j, char col) {
    if (a[i][j] == col) return true;
    else {
        bool ok = 0, ok1 = 0;
        for (int k = 0; k < m; ++k) 
            if (k != j && a[i][k] == col) 
                ok = 1;
        for (int k = 0; k < n; ++k)
            if (i != k && a[k][j] == col) 
                ok1 = 1;
        return ok && ok1;
    }
}

bool fun(char col) {
    int cnt = 0;
    cnt += can(0, 0, col) && can(n - 1, m - 1, col);
    cnt += can(n - 1, 0, col) && can(0, m - 1, col);
    return cnt >= 2;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    bool ret = fun('W') || fun('B');
    cout << (ret ? "YES\n" : "NO\n");
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
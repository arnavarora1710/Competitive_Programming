// https://codeforces.com/problemset/problem/1914/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
int n;
pi a[3][100005];
vector<vector<pi>> b;

void solve() {
    cin >> n; b.clear();
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < n; ++j) cin >> a[i][j].f;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < n; ++j) a[i][j].s = j;
    sort(a[0], a[0] + n, greater<pi>());
    sort(a[1], a[1] + n, greater<pi>());
    sort(a[2], a[2] + n, greater<pi>());
    int ans = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (a[0][i].s != a[1][j].s &&
                    a[1][j].s != a[2][k].s &&
                    a[0][i].s != a[2][k].s) {
                    int sum = a[0][i].f + a[1][j].f + a[2][k].f;
                    ans = max(ans, sum);
                }
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
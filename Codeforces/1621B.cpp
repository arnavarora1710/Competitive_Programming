// https://codeforces.com/contest/1621/problem/B
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
int n;

bool encompass(vector<int>& x, vector<int>& y) {
    return x[0] <= y[0] && y[1] <= x[1];
}

int calc(vector<int>& x, vector<int>& y) {
    if (encompass(x, y) && encompass(y, x)) return min(x[2], y[2]);
    else if (encompass(x, y)) return x[2];
    else if (encompass(y, x)) return y[2];
    else return x[2] + y[2];
}

// {l, r, cost}
// minm cost segment that goes the most left
// minm cost segment that goes the most right
void solve() {
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3));
    for (int i = 0; i < n; ++i) cin >> a[i][0] >> a[i][1] >> a[i][2];
    int l = inf, r = -inf, indl = -1, indr = -1, len = -inf, indlen = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i][0] < l) {
            l = a[i][0];
            indl = i;
        } else if (a[i][0] == l) {
            if (a[i][2] < a[indl][2]) {
                indl = i;
            }
        }
        if (a[i][1] > r) {
            r = a[i][1];
            indr = i;
        } else if (a[i][1] == r) {
            if (a[i][2] < a[indr][2]) {
                indr = i;
            }
        }
        if (len < a[i][1] - a[i][0] + 1) {
            len = a[i][1] - a[i][0] + 1;
            indlen = i;
        } else if (len == a[i][1] - a[i][0] + 1) {
            if (a[i][2] < a[indlen][2]) {
                indlen = i;
            }
        }
        int ans = calc(a[indl], a[indr]);
        if (len == r - l + 1) 
            ans = min(ans, a[indlen][2]);
        cout << ans << '\n';
    } 
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
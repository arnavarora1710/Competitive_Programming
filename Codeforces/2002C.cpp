// https://codeforces.com/contest/2002/problem/C
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
const int maxn = 2e5 + 5, inf = 1e18, eps = 1e-15;
int n, xs, ys, xt, yt;
pi a[maxn];

int dist(int ox, int oy, int nx, int ny) {
    return (ox - nx) * (ox - nx) + (oy - ny) * (oy - ny);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i].f >> a[i].s;
    cin >> xs >> ys >> xt >> yt;
    int dis = dist(xs, ys, xt, yt);
    for (int i = 0; i < n; ++i) {
        int dis1 = dist(a[i].f, a[i].s, xt, yt);
        if (dis >= dis1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

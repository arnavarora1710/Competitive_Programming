// https://codeforces.com/contest/1730/problem/B
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
const double eps = 1e-9;
int n, a[maxn], b[maxn];

double f(double m) {
    double ans = 0;
    for (int i = 0; i < n; ++i)
        ans = max(ans, abs(a[i] - m) + b[i]);
    return ans;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    double l = 0, r = inf;
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1), f2 = f(m2);
        if (f1 > f2) l = m1;
        else r = m2;
    }
    cout << fixed << setprecision(15) << l << '\n';
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

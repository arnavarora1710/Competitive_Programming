// https://codeforces.com/contest/1616/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (1)
const int maxn = 75, inf = 1e18;
int n;
double a[maxn];
const double EPS = 1e-9;

bool cmp(double x, double y) {
    return abs(x - y) >= EPS;
}

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = n - 1;
    vector<double> b(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            b[j] = a[j], b[i] = a[i];
            double d = (a[j] - a[i]) / (double) (j - i);
            for (int k = i + 1; k < n; ++k) b[k] = b[k - 1] + d;
            for (int k = i - 1; k >= 0; --k) b[k] = b[k + 1] - d;
            int cnt = 0;
            for (int k = 0; k < n; ++k) cnt += cmp(a[k], b[k]);
            ans = min(ans, cnt);
            d = -d;
            for (int k = i + 1; k < n; ++k) b[k] = b[k - 1] + d;
            for (int k = i - 1; k >= 0; --k) b[k] = b[k + 1] - d;
            cnt = 0;
            for (int k = 0; k < n; ++k) cnt += cmp(a[k], b[k]);
            ans = min(ans, cnt);
        }
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
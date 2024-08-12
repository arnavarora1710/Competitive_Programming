#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define PI acos(-1)
typedef pair<int, int> pi;
typedef pair<double, double> pd;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
int n;
double r;
pd a[maxn];

double dist(double ox, double oy, double nx, double ny) {
    return sqrt((ox - nx) * (ox - nx) + (oy - ny) * (oy - ny));
}

void solve() {
    cin >> n >> r;
    for (int i = 0; i < n; ++i) cin >> a[i].f >> a[i].s;
    if (n == 1) cout << fixed << setprecision(2) << 2 * PI * r;
    else {
        double ans = 2 * PI * r;
        for (int i = 0; i < n; ++i) {
            ans += dist(a[i].f, a[i].s, a[(i + 1) % n].f, a[(i + 1) % n].s);
        }
        cout << fixed << setprecision(2) << ans;
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

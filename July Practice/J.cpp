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
int x, y, k;

void solve() {
    cin >> x >> y >> k;
    while (k) {
        int nx = ((x + y - 1) / y) * y;
        if (x == nx) x++, k--;
        nx = ((x + y - 1) / y) * y;
        int d = nx - x;
        if (k - d < 0) break;
        k -= d;
        x = nx;
        while (x % y == 0) x /= y;
        if (x == 1) break;
    }
    if (x == 1) x = (x - 1 + k) % (y - 1) + 1;
    else x += k;
    cout << x << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

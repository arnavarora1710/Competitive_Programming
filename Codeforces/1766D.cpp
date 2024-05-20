// https://codeforces.com/contest/1766/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 1e7 + 5, inf = 1e18;
int x, y;

vector<int> spf(maxn + 1, 1);
 
void sieve() {
    spf[0] = 0;
    for (int i = 2; i <= maxn; i++) {
        if (spf[i] == 1) {
            for (int j = i; j <= maxn; j += i) {
                if (spf[j]== 1)
                    spf[j] = i;
            }
        }
    }
}

void solve() {
    cin >> x >> y;
    if (x&1 && y&1) cout << (gcd(x,y) == 1) << '\n';
    else if (!(x&1) && !(y&1)) cout << 0 << '\n';
    else if (y == x + 1) cout << -1 << '\n';
    else {
        int d = y - x;
        int mn = inf;
        while (d != 1) {
            mn = min(mn, (spf[d] * ((x + spf[d] - 1) / spf[d])) - x);
            d /= spf[d];
        }
        cout << mn << '\n';
    }
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sieve();
    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using mint = atcoder::modint998244353;
#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18, mod = 998244353;
int n, k;

mint power(mint x, mint y) {
    mint res = 1;
    while (y) {
        if (y&1) res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}

void solve() {
    cin >> n >> k;
    mint p = 1;
    mint nsq = n * n;
    for (int i = 1; i <= k; ++i) {
        mint pc = (1 - p) / (n - 1);
        mint c = 0;
        c += p / nsq;
        c += (p * (n - 1) * (n - 1)) / nsq; 
        c += (pc * (n - 1)) / nsq;
        c += (pc * (n - 1)) / nsq;
        p = c;
    }
    mint x = (n + 2) / 2;
    mint ans = p + x * (1 - p);
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

// https://codeforces.com/problemset/problem/233/B
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int inf = 1e18;
int n;

int dig(int m) {
    int ans = 0;
    while (m) {
        ans += (m%10);
        m /= 10;
    }
    return ans;
}

void solve() {
    cin >> n;
    int ans = inf;
    for (int k = 1; k <= 81; ++k) {
        int val = k * k + 4 * n;
        int sq = sqrt(val);
        if (sq * sq == val) {
            if ((sq + k) % 2 == 0) {
                int r1 = (sq + k) / 2, r2 = (sq - k) / 2;
                if (r1 > 0 && dig(r1) == k) ans = min(ans, r1);
                if (r2 > 0 && dig(r2) == k) ans = min(ans, r2);
            }
        }
    }
    cout << (ans == inf ? -1 : ans);
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

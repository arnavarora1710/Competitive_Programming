// https://codeforces.com/contest/1731/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, a[maxn];

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> m(2 * n); m[0] = 1;
    int ans = (n * (n + 1)) / 2;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        cur = cur ^ a[i];
        for (int j = 0; j * j < 2 * n; ++j)
            if ((cur ^ (j * j)) < 2 * n) ans -= m[cur ^ (j * j)];
        m[cur]++;
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
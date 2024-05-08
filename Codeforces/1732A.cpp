// https://codeforces.com/contest/1732/problem/A
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 20, inf = 1e18;
int n, a[maxn];

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    int g = 0;
    for (int i = 0; i < n; ++i) g = gcd(g, a[i]);
    if (g == 1) cout << 0 << endl;
    else if (gcd(g, n) == 1) cout << 1 << endl;
    else if (gcd(g, n - 1) == 1) cout << 2 << endl;
    else cout << 3 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

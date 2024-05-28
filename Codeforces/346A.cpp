// https://codeforces.com/problemset/problem/346/a
#pragma gcc optimize("ofast")
#pragma gcc optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define multi_test (0)
const int maxn = 105, inf = 1e18;
int n, a[maxn];

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    int g = 0;
    for (int i = 0; i < n; ++i) g = gcd(g, a[i]);
    int mx = *(max_element(a, a + n));
    mx /= g;
    if ((mx - n)&1) cout << "Alice";
    else cout << "Bob";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (multi_test) cin >> t;
    while (t--) solve();

    return 0;
}

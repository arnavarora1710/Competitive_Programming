// https://codeforces.com/contest/1990/problem/B
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
int n, x, y;

void solve() {
    cin >> n >> x >> y;
    x--, y--;
    vector<int> a(n, -1);
    for (int i = y; i <= x; ++i) a[i] = 1;
    bool flip = 1;
    for (int i = x + 1; i < n; ++i) a[i] = (flip ? -1 : 1), flip = !flip;
    flip = 1;
    for (int i = y - 1; i >= 0; --i) a[i] = (flip ? -1 : 1), flip = !flip;
    for (auto& v : a) cout << v << ' ';
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
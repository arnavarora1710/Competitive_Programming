// https://codeforces.com/contest/1257/problem/A
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
int n, x, a, b;

void solve() {
    cin >> n >> x >> a >> b;
    if (a > b) swap(a, b);
    while (x && a > 1) x--, a--;
    while (x && b < n) x--, b++;
    cout << b - a << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

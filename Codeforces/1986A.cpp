// https://codeforces.com/contest/1986/problem/A
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
int n, a[maxn];

void solve() {
    int x, y, z; cin >> x >> y >> z;
    int mn = inf;
    for (int i = -100; i <= 100; ++i) {
        int d = abs(i - x) + abs(i - y) + abs(i - z);
        mn = min(mn, d);
    }
    cout << mn << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

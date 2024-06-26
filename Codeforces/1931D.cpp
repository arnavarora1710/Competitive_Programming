// https://codeforces.com/problemset/problem/1931/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
int n, x, y, a[200005];
map<pi, int> m;

void solve() {
    cin >> n >> x >> y;
    for (int i = 0; i < n; ++i) cin >> a[i];
    m.clear();
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += m[{(x - a[i] % x) % x, a[i] % y}];
        m[{a[i] % x, a[i] % y}]++;
    }
    cout << cnt << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
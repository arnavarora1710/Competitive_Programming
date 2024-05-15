// https://codeforces.com/contest/1850/problem/G
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
int n, x, y;
map<int, int> mx, my, mr, mr1;

void solve() {
    mx.clear(); my.clear(); mr.clear(); mr1.clear();
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        ans += 2 * (mx[x] + my[y] + mr[x - y] + mr1[x + y]);
        mx[x]++;
        my[y]++;
        mr[x - y]++;
        mr1[x + y]++;
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
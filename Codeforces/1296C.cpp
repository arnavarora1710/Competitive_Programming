// https://codeforces.com/contest/1296/problem/C
#include <valarray>
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
int n; string s;

void solve() {
    cin >> n >> s;
    map<pi, int> mp;
    int curx = 0, cury = 0, prx = 0, pry = 0;
    mp[{0, 0}] = 0;
    int mn = inf, l = -1, r = -1;
    for (int i = 0; i < n; ++i) {
        curx = prx + (s[i] == 'R') - (s[i] == 'L');
        cury = pry + (s[i] == 'U') - (s[i] == 'D');
        prx = curx, pry = cury;
        if (mp.count({curx, cury})) {
            if (i - mp[{curx, cury}] < mn) {
                mn = i - mp[{curx, cury}];
                l = mp[{curx, cury}] + 1;
                r = i + 1;
            }
        }
        mp[{curx, cury}] = i + 1;
    }
    if (mn == inf) cout << -1 << '\n';
    else cout << l << ' ' << r << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

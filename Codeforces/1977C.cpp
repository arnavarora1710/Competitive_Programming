// https://codeforces.com/contest/1977/problem/C
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
const int maxn = 2e3 + 5, inf = 1e18;
int n, a[maxn];
map<int, int> cnt;

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    cnt.clear();
    for (int i = 0; i < n; ++i) cnt[a[i]]++;
    int ans = 0;
    for (auto u : cnt) {
        int tot = 0, cur = u.f;
        bool ok = 0;
        for (auto v : cnt) {
            if (u.f % v.f == 0) tot += v.s;
            else {
                if (!cnt.count(lcm(v.f, cur))) {
                    cur = lcm(v.f, cur);
                    tot += v.s;
                    ok = 1;
                }
            }
        }
        if (ok)
            ans = max(ans, tot);
        tot = 0, cur = u.f, ok = 0;
        for (auto it = cnt.rbegin(); it != cnt.rend(); ++it) {
            if (u.f % it->f == 0) tot += it->s;
            else {
                if (!cnt.count(lcm(it->f, cur))) {
                    cur = lcm(it->f, cur);
                    tot += it->s;
                    ok = 1;
                }
            }
        }
        if (ok) ans = max(ans, tot);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

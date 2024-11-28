// https://codeforces.com/contest/1984/problem/D
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
string s;

void solve() {
    cin >> s;
    int n = s.size();
    map<char, int> cnt;
    for (int i = 0; i < n; ++i) cnt[s[i]]++;
    if (cnt.size() > 2 || !cnt.count('a'))
        cout << 1 << '\n';
    else if (cnt.size() == 1) cout << n - 1 << '\n';
    else {
        int left = 0;
        vector<pi> res;
        for (int i = 0; i < n; ++i) {
            if (s[i] != 'a') {
                if (!res.empty()) res.back().s = left;
                res.push_back({left, 0});
                left = 0;
            } else left++;
        }
        if (!res.empty()) res.back().s = left;
        int mnleft = inf, mnright = inf;
        // for (pi v : res) cerr << v.f << ' ' << v.s << '\n';
        for (pi v : res) 
            mnleft = min(mnleft, v.f), mnright = min(mnright, v.s);
        int stuff;
        for (auto v : cnt) {
            if (v.f != 'a') stuff = v.f;
        }
        int ans = (1 << mnleft) + (1 << mnright) - (cnt[stuff] == 1 && (s.back() != 'a' || s.front() != 'a'));
        // cerr << ans << '\n';
        for (auto v : cnt) {
            if (v.f != 'a') ans += (v.s >= 2);
        }
        cout << ans << '\n';
        // cerr << "MNLEFT : " << mnleft << " MNRIGHT: " << mnright << '\n';
        // cerr << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

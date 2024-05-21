// https://codeforces.com/contest/1809/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int c1 = 1e12, c2 = c1 + 1, inf = 1e18;
string s;

void solve() {
    cin >> s; int n = s.size();
    int z = 0, o = count(s.begin(), s.end(), '1');
    int ans = inf;
    if (n == 1) ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        z += (s[i] == '0');
        o -= (s[i] == '1');
        int rem = z + o + (s[i] == '1') + (s[i + 1] == '0');
        int cur = (n - rem) * c2;
        if (s[i] > s[i + 1]) cur += c1;
        ans = min(ans, cur);
    }
    cout << ans << '\n';
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

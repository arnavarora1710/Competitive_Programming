// https://codeforces.com/contest/1993/problem/A
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
int n;
string s;

void solve() {
    cin >> n >> s;
    map<char, int> cnt;
    for (int i = 0; i < 4 * n; ++i) cnt[s[i]]++;
    int ans = 0;
    for (auto& v : cnt) 
        if (v.f != '?') ans += min(n, v.s);
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

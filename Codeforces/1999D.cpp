// https://codeforces.com/contest/1999/problem/D
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
string s, t;

void solve() {
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (j >= m) break;
        if (s[i] == t[j]) j++;
        else if (s[i] == '?') s[i] = t[j++];
    }
    for (int i = 0; i < n; ++i)
        if (s[i] == '?') s[i] = 'a';
    if (j < m) cout << "NO\n";
    else cout << "YES\n" << s << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

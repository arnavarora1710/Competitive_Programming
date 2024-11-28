// https://codeforces.com/contest/1837/problem/C
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
    if (s.back() == '?') s.back() = '1';
    if (s[0] == '?') s[0] = '0';
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') {
            if (s[i - 1] == '0' && s[i + 1] != '1') {
                s[i] = '0';
            } else s[i] = '1';
        }
    }
    cout << s << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

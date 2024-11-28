// https://codeforces.com/contest/131/problem/A
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
string s;

void solve() {
    cin >> s;
    bool ok = 1;
    for (int i = 1; i < s.size(); ++i) {
        ok &= (s[i] >= 'A' && s[i] <= 'Z');
    }
    if (ok) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
            else s[i] -= 32;
        }
        cout << s;
    } else cout << s;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

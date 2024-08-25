// https://codeforces.com/contest/1994/problem/B
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

void solve() {
    int n; string s, t;
    cin >> n >> s >> t;
    bool ok = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            ok = true;
        }
        if (s[i] != t[i] && !ok) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

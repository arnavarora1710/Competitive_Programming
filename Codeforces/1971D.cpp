// https://codeforces.com/contest/1971/problem/D
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
string s;

void solve() {
    cin >> s;
    int n = s.size(), ans = 0;
    bool flag = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            ans++;
            while (i < n && s[i] != '1') i++;
            if (!flag) {
                while (i < n && s[i] != '0') i++;
                flag = 1;
            }
            i--;
        } else {
            ans++;
            while (i < n && s[i] != '0') i++;
            i--;
        }
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
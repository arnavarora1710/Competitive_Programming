// https://codeforces.com/contest/1997/problem/A
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
    string ans;
    bool ok = 0;
    for (int i = s.size() - 2; i >= 0; --i) {
        if (!ok && s[i] == s[i + 1]) {
            ans.push_back(s[i] == 'z' ? 'a' : s[i] + 1);
            ok = 1;
        }
        ans.push_back(s[i]);
    }
    reverse(ans.begin(), ans.end());
    cout << ans + s.back();
    if (!ok) cout << (s.back() == 'z' ? "a" : "z");
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

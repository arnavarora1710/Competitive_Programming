// https://codeforces.com/problemset/problem/1560/E
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
string s; map<char, int> m, want;

void solve() {
    cin >> s; m.clear(); want.clear();
    string ans, order;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (!m.count(s[i])) order.push_back(s[i]);
        m[s[i]]++;
    }
    int sz = m.size();
    for (char c : order) want[c] = m[c] / sz--;
    reverse(order.begin(), order.end());
    int i = 0;
    while (i < s.size() && want.size()) {
        ans.push_back(s[i]);
        want[s[i]]--;
        if (want[s[i]] == 0) want.erase(s[i]);
        i++;
    }
    string ss = ans;
    string prev = ans;
    for (char c : order) {
        string nn;
        for (int j = 0; j < prev.size(); ++j) {
            if (prev[j] != c) nn.push_back(prev[j]);
        }
        ss += nn;
        prev = nn;
    }
    if (ss == s) cout << ans << " " << order << endl;
    else cout << -1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
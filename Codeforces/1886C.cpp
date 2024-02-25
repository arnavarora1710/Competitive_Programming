// https://codeforces.com/contest/1886/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
string s; int pos; 

void solve() {
    cin >> s >> pos; --pos;
    int n = s.size();
    bool stop = pos < n;
    s += '$';
    vector<char> ss;
    for (int i = 0; i < s.size(); ++i) {
        while (!stop && !ss.empty() && ss.back() > s[i]) {
            pos -= n--;
            ss.pop_back();
            if (pos < n) stop = true;
        }
        ss.push_back(s[i]);
    }
    cout << ss[pos];
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
// jbka
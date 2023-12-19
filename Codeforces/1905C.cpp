// https://codeforces.com/contest/1905/problem/C
#include <bits/stdc++.h>
using namespace std;
int t, n; string s; map<char, vector<int>> m;

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> s;
        m.clear(); for (int i = 0; i < n; ++i) m[s[i]].push_back(i);
        int prev = -1, count = 0; vector<int> a;
        for (auto it = m.rbegin(); it != m.rend(); ++it) {
            for (auto& ele : it->second) {
                if (ele > prev) {
                    a.push_back(ele);
                    if (m.rbegin()->first == it->first) count++;
                }
            }
            prev = a.back();
        }
        int ans = a.size() - count;
        for (int i = 0; i < a.size() - i - 1; ++i) swap(s[a[i]], s[a[a.size() - i - 1]]);
        string s1 = s; sort(s1.begin(), s1.end());
        if (s1 == s) cout << ans << endl;
        else cout << -1 << endl;
    }
    return 0;
}
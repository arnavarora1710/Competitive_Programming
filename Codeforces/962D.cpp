// https://codeforces.com/contest/962/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
int n, a[maxn];

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i)
        mp[a[i]].push_back(i);
    vector<int> res(n);
    for (auto v : mp) {
        sort(v.s.begin(), v.s.end());
        int val = v.s.size();
        if (val&1) res[v.s.back()] = v.f;
        for (int i = 1; i < val; i+=2)
            mp[v.f * 2].push_back(v.s[i]);
    }
    vector<int> ans;
    for (int i : res) if (i) ans.push_back(i);
    cout << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

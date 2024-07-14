// https://codeforces.com/contest/1492/problem/C
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
int n, m;
string s, t;

void solve() {
    cin >> n >> m >> s >> t;
    map<char, vector<int>> mp;
    for (int i = 0; i < n; ++i)
        mp[s[i]].push_back(i);
    vector<int> pr(m), suf(m);
    pr[0] = mp[t[0]][0];
    for (int i = 1; i < m; ++i) {
        int l = -1, r = mp[t[i]].size();
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (mp[t[i]][mid] > pr[i - 1]) r = mid;
            else l = mid;
        }
        pr[i] = mp[t[i]][r];
    }
    suf[m - 1] = mp[t[m - 1]].back();
    for (int i = m - 2; i >= 0; --i) {
        int l = -1, r = mp[t[i]].size();
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (mp[t[i]][mid] < suf[i + 1]) l = mid;
            else r = mid;
        }
        suf[i] = mp[t[i]][l];
    }
    int ans = 0;
    for (int i = 0; i + 1 < m; ++i) 
        ans = max(ans, suf[i + 1] - pr[i]);
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

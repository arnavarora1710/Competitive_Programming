// https://codeforces.com/contest/1971/problem/G
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
int n, a[maxn];

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    set<int> s;
    map<int, int> cnt;
    map<int, vector<int>> cnt1;
    vector<int> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        cnt[a[i] & (~3)]++;
        cnt1[a[i]].push_back(i);
    }
    for (auto v : cnt) {
        set<int> ind;
        for (int i = 0; i <= 3; ++i) {
            int val = (v.f | i);
            for (int j : cnt1[val]) ind.insert(j);
        }
        vector<int> index(ind.begin(), ind.end());
        int k = 0;
        for (int i = 0; i <= 3; ++i) {
            int val = (v.f | i);
            for (int j = 0; j < cnt1[val].size(); ++j) ans[index[k++]] = val;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (ans[i] == -1) ans[i] = a[i];
    }
    for (int i : ans) cout << i << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
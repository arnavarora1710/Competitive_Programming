// https://codeforces.com/contest/1926/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
const int maxn = 200005;
int n, a[maxn];

void print(vector<int> aa) {
    for (int aaa : aa) cout << aaa << " ";
    cout << endl;
}

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    map<vector<int>, int> m;
    for (int i = 0; i < n; ++i) {
        vector<int> bit_repr;
        for (int bit = 30; bit >= 0; --bit)
            bit_repr.push_back((a[i] & (1 << bit)) > 0);
        m[bit_repr]++;
    }
    int ans = 0;
    for (auto& pp : m) {
        vector<int> flipped(pp.first.begin(), pp.first.end());
        for (int i = 0; i < 31; ++i)
            flipped[i] = !flipped[i];
        int count_orig = pp.second;
        int count_flipped = m[flipped];
        if (count_orig < count_flipped) {
            ans += count_orig;
            m[flipped] -= count_orig; 
        } else {
            ans += count_orig;
            m[flipped] = 0;
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
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
int n; vector<pair<int, int>> ans;

void toh(int discs, int from, int to, int use) {
    if (!discs) return;
    toh(discs - 1, from, use, to);
    ans.push_back({from, to});
    toh(discs - 1, use, to, from);
}

void solve() {
    cin >> n;
    toh(n, 1, 3, 2);
    cout << ans.size() << endl;
    for (auto& p : ans) cout << p.first << " " << p.second << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
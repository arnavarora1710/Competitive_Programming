// https://codeforces.com/contest/1925/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n, k, m; string a;

void solve() {
    cin >> n >> k >> m >> a;
    string ans; vector<bool> occ(k);
    int cnt = 0;
    for (char ch : a) {
        if (ans.size() == n) break;
        cnt += (!occ[ch - 'a']);
        occ[ch - 'a'] = true;
        if (cnt == k) {
            occ.assign(k, 0);
            cnt = 0;
            ans.push_back(ch);
        }
    }
    if (ans.size() == n) cout << "YES\n";
    else {
        cout << "NO\n";
        for (int i = 0; i < k; ++i) {
            if (!occ[i]) {
                while (ans.size() != n) ans.push_back('a' + i);
            }
        }
        cout << ans << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
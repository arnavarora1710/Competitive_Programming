// https://codeforces.com/problemset/problem/1915/D
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n; string a;

void solve() {
    cin >> n >> a; string ans;
    set<char> c = {'b', 'c', 'd'}; int i = n - 1;
    while (i >= 0) {
        if (c.find(a[i]) != c.end()) for (int _ = 0; _ < 3; ++_) ans.push_back(a[i--]);
        else for (int _ = 0; _ < 2; ++_) ans.push_back(a[i--]);
        ans.push_back('.');
    }
    ans.pop_back(); reverse(ans.begin(), ans.end());
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
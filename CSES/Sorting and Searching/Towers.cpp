#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
int n, x; multiset<int> s;

void solve() {
    cin >> n; int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        auto it = s.upper_bound(x);
        if (it != s.end()) s.erase(it), s.insert(x);
        else s.insert(x), ans++;
    }
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
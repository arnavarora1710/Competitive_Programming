#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
int n, m, x; multiset<int> s;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> x, s.insert(x);
    for (int i = 0; i < m; ++i) {
        cin >> x; auto it = s.upper_bound(x);
        if (it != s.begin()) {
            cout << *prev(it) << endl;
            s.erase(prev(it));
        } else cout << -1 << endl; 
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
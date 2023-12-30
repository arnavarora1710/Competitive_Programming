#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
int k, n, x; 
set<int> l; multiset<int> d;

void solve() {
    cin >> k >> n;
    l.insert(0), l.insert(k);
    d.insert(k);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        auto it = l.upper_bound(x);
        d.erase(d.find(*it - *(prev(it))));
        d.insert(x - *(prev(it)));
        d.insert(*it - x);
        l.insert(x);
        cout << *d.rbegin() << " ";
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
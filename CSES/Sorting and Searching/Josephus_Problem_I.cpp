#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
int n;

void solve() {
    cin >> n;
    set<int> s; for (int i = 1; i <= n; ++i) s.insert(i);
    set<int>::iterator it = s.begin();
    advance(it, 1);
    while (s.size() != 1) {
        cout << *it << " ";
        auto it1 = it;
        if (it == prev(s.end())) it = s.begin(), advance(it, 1);
        else if (it == prev(prev(s.end()))) it = s.begin();
        else advance(it, 2);
        s.erase(it1);
    }
    cout << *s.rbegin() << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
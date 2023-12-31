#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define MULTI_TEST (0)
int n, a[200005];

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    set<pi> s = {make_pair(a[0], 1)}; cout << "0 ";
    for (int i = 1; i < n; ++i) {
        auto it = s.upper_bound(make_pair(a[i], LLONG_MIN));
        if (it == s.begin()) cout << "0 ";
        else {
            pi p = *prev(it);
            cout << p.second << " ";
        }
        s.erase(it, s.end());
        s.insert({a[i], i + 1});
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
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n; string a; map<char, int> m;

void solve() {
    cin >> n >> a; m.clear();
    for (int i = 0; i < n; ++i) m[a[i]]++;
    int ans = n;
    for (int i = n - 1; i >= 0; --i) {
        m[a[i]]--;
        for (auto& x : m) {
            if (x.first != a[i]) {
                if (x.second != 0) ans++;
            }
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
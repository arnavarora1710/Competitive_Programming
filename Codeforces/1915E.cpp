// https://codeforces.com/problemset/problem/1915/E
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
const int maxn = 200005;
int n, a[maxn]; map<int, int> m;

void solve() {
    cin >> n; m.clear();
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i&1) a[i] *= -1;
    }
    int s = 0; m[0] = 1;
    for (int i = 0; i < n; ++i) {
        s += a[i];
        if (m.count(s)) {
            cout << "YES\n"; return;
        }
        m[s]++;
    }
    cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
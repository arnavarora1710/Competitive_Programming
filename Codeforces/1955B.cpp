// https://codeforces.com/contest/1955/problem/B
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 505, inf = 1e18;
int n, c, d;

void solve() {
    cin >> n >> c >> d;
    vector<int> a(n * n);
    for (int i = 0; i < n * n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    vector<bool> vis(n * n);
    multiset<int> s(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int val = a[0] + j * d + i * c;
            if (s.find(val) == s.end()) {
                cout << "NO\n";
                return;
            } else s.erase(s.find(val));
            // bool ok = 0;
            // for (int k = 0; k < n * n; ++k) {
            //     if (!vis[k] && a[k] == val) {
            //         ok = 1;
            //         vis[k] = true;
            //         break;
            //     }
            // }
            // if (!ok) {
            //     cout << "NO\n";
            //     return;
            // }
        }
    }
    // for (int i = 0; i + 1 < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         if (a[i + 1][j] != a[i][j] + c) {
    //             cout << "NO\n";
    //             return;
    //         }
    //     }
    // }
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j + 1 < n; ++j) {
    //         if (a[i][j + 1] != a[i][j] + d) {
    //             cout << "NO\n";
    //             return;
    //         }
    //     }
    // }
    cout << "YES\n";

}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
// https://codeforces.com/contest/1742/problem/G
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, a[maxn];

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    int cur = 0;
    vector<bool> vis(n);
    for (int i = 0; i < min(32LL, n); ++i) {
        int mx = 0, idx = -1;
        for (int j = 0; j < n; ++j) {
            if (vis[j]) continue;
            if ((cur | a[j]) > mx) {
                mx = cur | a[j];
                idx = j;
            }
        }
        cout << a[idx] << " ";
        cur = mx;
        vis[idx] = true;
    }
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) cout << a[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
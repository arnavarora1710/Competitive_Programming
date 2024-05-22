// https://codeforces.com/contest/1758/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n;

void solve() {
    cin >> n;
    if (n&1) {
        vector<int> ans(n);
        int j = 0;
        for (int i = n / 2; i; --i, ++j) ans[j] = n - i;
        ans[n / 2] = n;
        j++;
        for (int i = 1; i <= n / 2; ++i, ++j) ans[j] = n + i;
        ans[0]--, ans[n - 1]++;
        for (int i = 0; i < n; ++i) ans[i] += 2;
        ans[n - 2]++;
        for (int i : ans) cout << i << ' ';
        cout << '\n';
    } else {
        for (int i = n / 2; i; --i) cout << n - i << ' ';
        for (int i = 1; i <= n / 2; ++i) cout << n + i << ' ';
        cout << '\n';
    }
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

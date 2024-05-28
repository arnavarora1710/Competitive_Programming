// https://codeforces.com/contest/1975/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, a[maxn];

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    if (n == 2) {
        cout << min(a[0], a[1]) << '\n';
        return;
    }
    int mx = 0;
    for (int i = 0; i + 2 < n; ++i) {
        vector<int> b(a + i, a + i + 3);
        sort(b.begin(), b.end());
        mx = max(mx, b[1]);
    }
    cout << mx << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

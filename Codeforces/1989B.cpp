// https://codeforces.com/contest/1989/problem/B
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
string a, b;

void solve() {
    cin >> a >> b;
    int n = a.size(), m = b.size();
    int ans = inf;
    for (int j = 0; j < m; ++j) {
        int k = j;
        for (int i = 0; i < n; ++i) {
            if (a[i] == b[k]) k++;
        }
        ans = min(ans, j + n + m - k);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

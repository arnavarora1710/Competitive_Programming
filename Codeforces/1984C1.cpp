// https://codeforces.com/contest/1984/problem/C1
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
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int c = 0;
    vector<int> tot;
    for (int i = 1; i <= n; ++i) {
        if (c + a[i] >= 0) c += a[i];
        else {
            c += a[i];
            tot.push_back(abs(2 * c));
        }
    }
    int ans = c;
    for (int i : tot) {
        ans = max(ans, c + i);
    }
    cout << ans << '\n';
    // cerr << "C: " << c << '\n';
    // for (int i : tot) cerr << i << ' ';
    // cerr << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

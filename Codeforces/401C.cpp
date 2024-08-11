// https://codeforces.com/contest/401/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
int n, m;

void solve() {
    cin >> n >> m;
    if (m < n - 1 || m > ((n + 1) << 1)) cout << -1;
    else if (m == n) {
        for (int i = 0; i < n; ++i) cout << "10";
    } else if (m == n - 1) {
        cout << 0;
        for (int i = 0; i < m; ++i) cout << "10";
    } else {
        for (int i = 0; i <= n; ++i) {
            int k = n - i + 1;
            if (m > k) {
                cout << "11";
                m -= 2;
            } else {
                cout << 1;
                m--;
            }
            if (i != n) cout << 0;
        }
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

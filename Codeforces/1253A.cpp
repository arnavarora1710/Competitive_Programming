// https://codeforces.com/contest/1253/problem/A
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
int n;

void solve() {
    cin >> n;
    vector<int> a(n), b(n), d(n + 2);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i) {
        d[i] = b[i - 1] - a[i - 1];
        if (d[i] < 0) {
            cout << "NO\n";
            return;
        }
    }
    int cnt = 0;
    for (int i = 0; i + 1 < n + 2; ++i)
        if (d[i] != d[i + 1]) cnt++;
    if (cnt > 2) cout << "NO\n";
    else cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

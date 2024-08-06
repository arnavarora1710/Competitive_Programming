// https://codeforces.com/contest/1999/problem/C
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
int n, s, m;
pi a[maxn];

void solve() {
    cin >> n >> s >> m;
    for (int i = 0; i < n; ++i) cin >> a[i].f >> a[i].s;
    sort(a, a + n);
    if (a[0].f >= s || m - a[n - 1].s >= s) {
        cout << "YES\n";
        return;
    }
    for (int i = 0; i + 1 < n; ++i) {
        int gap = a[i + 1].f - a[i].s;
        if (gap >= s) {
            cout << "YES\n";
            return;
        }
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

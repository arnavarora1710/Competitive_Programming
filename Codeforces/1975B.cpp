// https://codeforces.com/contest/1975/problem/B
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
    sort(a, a + n);
    int y = -1, x = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] % x) {
            y = a[i];
            break;
        }
    }
    if (y == -1) cout << "Yes\n";
    else {
        for (int i = 2; i < n; ++i) {
            if (a[i] % x == 0 || a[i] % y == 0) continue;
            else {
                cout << "No\n";
                return;
            }
        }
        cout << "Yes\n";
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

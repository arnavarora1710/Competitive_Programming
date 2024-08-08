// https://codeforces.com/contest/1997/problem/B
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
int n;
string a[2];

void solve() {
    cin >> n >> a[0] >> a[1];
    bool ok = 0;
    for (int i = 0; i < n; ++i) 
        ok = ok || (a[0][i] == '.' || a[1][i] == '.');
    if (!ok) {
        cout << 0 << '\n';
        return;
    }
    int ans = 0;
    for (int i = 1; i + 1 < n; ++i) {
        if (a[0][i] == '.' && a[1][i - 1] == 'x' && a[1][i + 1] == 'x'
            && a[0][i - 1] == '.' && a[0][i + 1] == '.' && a[1][i] == '.') {
                ans++;
        }
    }
    for (int i = 1; i + 1 < n; ++i) {
        if (a[1][i] == '.' && a[0][i - 1] == 'x' && a[0][i + 1] == 'x'
            && a[1][i - 1] == '.' && a[1][i + 1] == '.' && a[0][i] == '.') {
                ans++;
        }
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

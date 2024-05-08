// https://codeforces.com/contest/1948/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
int n; string a[2];
bool can[2][200005];

void solve() {
    cin >> n;
    memset(can[0], 0, n);
    memset(can[1], 0, n);
    for (int i = 0; i < 2; ++i) cin >> a[i];
    if (n&1) cout << "NO\n";
    else {
        can[0][0] = true;
        for (int i = 0; i + 1 < n; ++i) {
            if (!(i&1)) {
                if (can[0][i] || (i - 1 >= 0 && can[1][i - 1])) {
                    if (a[1][i] == '>') can[1][i + 1] = true;
                }
            }
            else {
                if (can[1][i] || (i - 1 >= 0 && can[0][i - 1])) {
                    if (a[0][i] == '>') can[0][i + 1] = true;
                }
            }
        }
        cout << (can[1][n - 1] ? "YES\n" : "NO\n");
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
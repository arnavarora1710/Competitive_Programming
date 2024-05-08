// https://codeforces.com/contest/1899/problem/F
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
int n, q, a[505];

void solve() {
    cin >> n >> q;
    for (int i = 0; i < q; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) cout << i << " " << i + 1 << endl;
    int pos = n - 1;
    for (int i = 0; i < q; ++i) {
        if (a[i] == pos || a[i] == n - pos) {
            cout << "-1 -1 -1\n";
        } else {
            cout << n << " " << pos << " " << a[i] << endl;
            pos = a[i];
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
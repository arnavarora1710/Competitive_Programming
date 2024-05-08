// https://codeforces.com/problemset/problem/1927/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
int n, q, l, r, a[200005], lookup[200005];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    lookup[0] = -1;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1]) lookup[i] = i - 1;
        else if (lookup[i - 1] == -1) lookup[i] = -1;
        else lookup[i] = lookup[i - 1];
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> l >> r;
        --l, --r;
        if (lookup[r] != -1 && lookup[r] >= l)
            cout << lookup[r] + 1 << " " << r + 1 << endl;
        else cout << -1 << " " << -1 << endl;
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
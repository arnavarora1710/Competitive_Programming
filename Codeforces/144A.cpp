// https://codeforces.com/problemset/problem/144/A
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
int n, a[105];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int mn = INT_MAX, mx = INT_MIN, id1 = -1, id2 = -1;
    for (int i = 0; i < n; ++i) {
        if (mn >= a[i]) mn = a[i], id1 = i;
        if (mx < a[i]) mx = a[i], id2 = i;
    }
    if (id2 > id1) cout << (n - id1 - 1) + id2 - 1 << endl;
    else if (id1 == id2) cout << 0 << endl;
    else cout << id2 + (n - id1 - 1) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
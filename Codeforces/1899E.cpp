// https://codeforces.com/contest/1899/problem/E
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
int n, a[200005];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    int i = n - 1;
    while (i >= 1 && a[i] >= a[i - 1]) --i;
    for (int j = 0; j < i; ++j) {
        if (a[j] <= a[i]) {
            cout << -1 << endl;
            return;
        }
    }
    cout << i << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
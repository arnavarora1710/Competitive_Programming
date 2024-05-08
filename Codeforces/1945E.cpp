// https://codeforces.com/contest/1945/problem/E
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
int n, x, a[200005];

void solve() {
    cin >> n >> x; int id = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == x) id = i;
    }
    int l = 0, r = n;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (a[m] <= x) l = m;
        else r = m;
    }
    cout << 1 << endl << id + 1 << " " << l + 1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
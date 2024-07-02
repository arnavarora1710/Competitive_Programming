// https://codeforces.com/problemset/problem/1491/D
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int x, y;

void submit(bool yes) {
    cout << (yes ? "YES\n" : "NO\n");
}

void solve() {
    cin >> x >> y;
    vector<int> indx, indy;
    for (int i = 0; i < 32; ++i) {
        int bitx = (x >> i)&1, bity = (y >> i)&1;
        if (bitx) indx.push_back(i);
        if (bity) indy.push_back(i);
    }
    bool ok = 1;
    for (int i = 0; i < indy.size(); ++i) {
        if (indy[i] < indx[i]) {
            ok = 0;
            break;
        }
    }
    submit(x <= y && ok && __builtin_popcount(x) >= __builtin_popcount(y));
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

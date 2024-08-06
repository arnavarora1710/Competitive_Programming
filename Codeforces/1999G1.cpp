// https://codeforces.com/contest/1999/problem/G1
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

// 16, 32, 64, 128, 256, 512
// m - 2, m
// (m - 2) * m
// (m - 2) * (m + 1)
// (m - 1) * (m + 1)
int check(int m) {
    cout << "? " << m << " " << m << endl;
    int res; cin >> res;
    return res == m * m;
}

void solve() {
    int l = 0, r = 1001;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    cout << "! " << r << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

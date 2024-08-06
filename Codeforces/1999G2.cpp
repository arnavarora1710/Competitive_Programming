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

int check(int m1, int m2) {
    cout << "? " << m1 << " " << m2 << endl;
    int res; cin >> res;
    if (res == m1 * m2) return 0;
    else if (res == m1 * (m2 + 1)) return 1;
    else return 2;
}

bool check1(int m) {
    cout << "? " << 1 << " " << m << endl;
    int res; cin >> res;
    return res == m;
}

void solve() {
    int l = 1, r = 1000;
    while (r - l > 2) {
        int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        int f = check(m1, m2);
        if (f == 0) {
            l = m2;
        } else if (f == 1) {
            l = m1;
            r = m2;
        } else if (f == 2) {
            r = m1;
        }
    }
    int L = l, R = r;
    while (R - L > 1) {
        int M = L + (R - L) / 2;
        if (check1(M)) L = M;
        else R = M;
    }
    cout << "! " << R << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

// https://codeforces.com/problemset/problem/439/D
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
const int mxn = 100005;
int n, m, a[mxn], b[mxn];

// ts to calc ops to get mm as the satisfactory condn
// want all ele of a to be at least mm
// want all ele of b to be at most mm
int f(int mm) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) cnt += max(0LL, mm - a[i]);
    for (int i = 0; i < m; ++i) cnt += max(0LL, b[i] - mm);
    return cnt;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    int l = -1, r = 1e9 + 1;
    while (r - l > 2) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        if (f(m1) > f(m2)) l = m1;
        else r = m2;
    }
    cout << f(r - 1) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
// https://codeforces.com/contest/1987/problem/C
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
int n, a[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> b(a, a + n);
    int tot = 0, add = 0;
    for (int i = n - 1; i >= 0; --i) {
        a[i] -= tot - add;
        if (i) add = max(0LL, add + b[i] - (a[i - 1] - 1));
        tot += a[i];
    }
    cout << tot << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

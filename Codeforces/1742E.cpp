// https://codeforces.com/problemset/problem/1742/E
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, q, k[maxn], a[maxn], pr[maxn], mx[maxn];

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];
    mx[0] = a[0];
    for (int i = 1; i < n; ++i) mx[i] = max(mx[i - 1], a[i]);
    pr[0] = a[0];
    for (int i = 1; i < n; ++i) pr[i] = pr[i - 1] + a[i];
    for (int i = 0; i < q; ++i) cin >> k[i];
    for (int i = 0; i < q; ++i) {
        int l = -1, r = n;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (k[i] >= mx[m]) l = m;
            else r = m;
        }
        if (l == -1) cout << 0 << " ";
        else cout << pr[l] << " ";
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
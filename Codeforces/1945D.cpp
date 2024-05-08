// https://codeforces.com/contest/1945/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 200005;
int n, m, a[maxn], b[maxn], s[maxn];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    int ans = 0;
    for (int i = n - 1; i >= m; --i) {
        ans += min(a[i], b[i]);
    }
    s[m - 1] = b[m - 1];
    for (int i = m - 2; i >= 0; --i) s[i] = s[i + 1] + b[i];
    int ans1 = LLONG_MAX;
    for (int i = 0; i < m; ++i) {
        int val = a[i] + (i + 1 < m ? s[i + 1] : 0);
        ans1 = min(ans1, val);
    }
    cout << ans + ans1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
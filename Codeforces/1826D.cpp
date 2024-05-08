// https://codeforces.com/contest/1826/problem/D
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
int n, a[maxn];

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> pr(n), suf(n);
    pr[0] = a[0], suf[n - 1] = a[n - 1] - n + 1;
    for (int i = 1; i < n; ++i) pr[i] = max(pr[i - 1], a[i] + i);
    for (int i = n - 2; i >= 0; --i) suf[i] = max(suf[i + 1], a[i] - i);
    int ans = -inf;
    for (int i = 1; i + 1 < n; ++i) {
        ans = max(ans, a[i] + pr[i - 1] + suf[i + 1]);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
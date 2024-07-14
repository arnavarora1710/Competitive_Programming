// https://codeforces.com/contest/1486/problem/B
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
const int maxn = 1e3 + 5, inf = 1e18;
int n, a[maxn], b[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    sort(a, a + n); sort(b, b + n);
    int ans = (a[n / 2] - a[(n - 1) / 2] + 1);
    ans *= (b[n / 2] - b[(n - 1) / 2] + 1);
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

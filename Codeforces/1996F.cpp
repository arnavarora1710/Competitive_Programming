// https://codeforces.com/contest/1996/problem/F
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
int n, k, ans, a[maxn], b[maxn];

int check(int m, bool fin = 0) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int val = (a[i] + b[i] - m - 1) / b[i];
        cnt += max(0LL, val);
        if (fin) {
            int a1 = a[i], an = a[i] - b[i] * val;
            int sum = (val * (2 * a1 - (val - 1) * b[i])) / 2;
            ans += max(0LL, sum);
            a[i] = max(0LL, an);
        }
    }
    return cnt;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    int l = -1, r = inf;
    ans = 0;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (check(m) > k) l = m;
        else r = m;
    }
    k -= check(r, 1);
    ans += (r * k);
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

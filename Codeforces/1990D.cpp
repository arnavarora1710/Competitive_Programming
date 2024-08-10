// https://codeforces.com/contest/1990/problem/D
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
    int ans = 0;
    bool ok1 = 0, ok2 = 0;
    for (int i = 0; i < n; ++i) {
        if (!ok1 && !ok2) {
            if (!a[i]) continue;
            else if (a[i] <= 2) ok1 = 1;
            ans++;
        } else if (ok1) {
            ok1 = 0;
            if (a[i] <= 2) continue;
            ans++;
            if (a[i] <= 4) ok2 = 1;
        } else {
            ok2 = 0;
            if (!a[i]) continue;
            ans++;
            if (a[i] <= 4) ok1 = 1;
        }
    }
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

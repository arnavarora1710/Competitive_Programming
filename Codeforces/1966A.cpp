// https://codeforces.com/contest/1966/problem/A
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
int n, k, a[maxn];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<pi> cnt(101);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cnt[a[i]].f++;
        ans++;
        cnt[a[i]].s = a[i];
    }
    // sort(cnt.begin(), cnt.end(), greater<pi>());
    while (1) {
        sort(cnt.begin(), cnt.end(), greater<pi>());
        if (cnt[0].f - k < 0) break;
        cnt[0].f -= k;
        sort(cnt.begin(), cnt.end(), greater<pi>());
        cnt[0].f += k - 1;
        ans--;
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
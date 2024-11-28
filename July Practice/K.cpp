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
int n, k, a[maxn];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> p(n), s(n), need(n), pr(n);
    for (int i = 0; i < n; ++i)
        pr[i] = (i ? pr[i - 1] : 0) + a[i]; 
    for (int i = 0; i < n; ++i)
        p[i] = max((i ? p[i - 1] : 0), a[i]);
    for (int i = n - 1; i >= 0; --i) 
        s[i] = max((i + 1 < n ? s[i + 1] : 0), a[i]);
    for (int i = 0; i < n; ++i) {
        int val1 = (i ? p[i - 1] : 0);
        int val2 = (i + 1 < n ? s[i + 1] : 0);
        int val3 = (i ? a[0] + k : 0);
        need[i] = max(val1, max(val2, val3));
        if (need[i] == val1 || need[i] == val3) {
            if (need[i] == a[i]) need[i]++;
        }
    }
    for (int i = 0; i < n; ++i) {
        int sum = (i ? pr[i - 1] : 0);
        if (a[i] >= need[i]) cout << 0 << ' ';
        else if (a[i] + sum + k >= (i + 1 < n ? s[i + 1] : 0)) cout << i << ' ';
        else cout << i + 1 << ' ';
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

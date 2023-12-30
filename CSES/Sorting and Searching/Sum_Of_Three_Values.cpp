#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
int n, k;

void solve() {
    cin >> n >> k; vector<pi> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i].f, a[i].s = i + 1;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            int targ = k - (a[i].f + a[j].f);
            pi p = {targ, LLONG_MIN};
            int it = lower_bound(a.begin() + j + 1, a.end(), p) - (a.begin() + j + 1);
            if (j + 1 + it < n && a[j + 1 + it].f == targ) {
                cout << a[i].s << " " << a[j].s << " " << a[j + 1 + it].s << endl;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE";
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
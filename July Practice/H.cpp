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

// min(xi ki) > sum(xi)
// xj kj > xj + othersum(xi)
// xj (kj - 1) > othersum(xi)
// fix sum = nx
// 1000 1000 1000
// 1001 1501 498

const int VAL = 1e8;

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<pi> b;
    for (int i = 0; i < n; ++i) b.push_back({a[i], i});
    sort(b.begin(), b.end());
    vector<int> ans(n, VAL);
    int sum = VAL * n;
    int i = 0, j = n - 1;
    while (i < j) {
        int need = (sum / a[b[i].s]) + 1 - ans[b[i].s];
        int cantake = ans[b[j].s] - ((sum / a[b[j].s]) + 1);
        if (need <= cantake) {
            ans[b[i++].s] += need;
            ans[b[j].s] -= need;
        } else {
            ans[b[i].s] += cantake;
            ans[b[j--].s] -= cantake;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (ans[i] * a[i] <= sum) {
            cout << -1 << '\n';
            return;
        }
    }
    for (auto& x : ans) cout << x << ' ';
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

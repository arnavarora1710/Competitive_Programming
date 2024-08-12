// https://codeforces.com/contest/1998/problem/C
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
const int maxn = 2e5 + 5, inf = 1e13;
int n, k;
pi a[maxn];

bool check(int m) {
    int total = 0;
    vector<int> cost(n);
    for (int i = 0; i < n; ++i) {
        if (a[i].f >= m) cost[i] = 0;
        else {
            if (a[i].s == 0) cost[i] = inf;
            else cost[i] = m - a[i].f;
        }
    }
    sort(cost.begin(), cost.end());
    for (int i = 0; i <= (n + 1) / 2; ++i)
        total += cost[i];
    return total <= k;
}

int calc() {
    int l = -1, r = inf;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    int left = k;
    vector<pi> cost(n);
    for (int i = 0; i < n; ++i) {
        if (a[i].f >= l) cost[i] = {0, i};
        else {
            if (a[i].s == 0) cost[i] = {inf, i};
            else cost[i] = {l - a[i].f, i};
        }
    }
    sort(cost.begin(), cost.end());
    for (int i = 0; i <= (n + 1) / 2; ++i) {
        if (cost[i].f >= inf) return 0;
        a[cost[i].s].f += cost[i].f;
        left -= cost[i].f;
    }
    sort(a, a + n);
    int med = (n + 1) / 2 - 1;
    int new_med = med - (n&1);
    return a[n - 1].f + (a[n - 1].s ? left : 0) + a[new_med].f;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i].f;
    for (int i = 0; i < n; ++i) cin >> a[i].s;
    sort(a, a + n);
    int ans = 0;
    int med = (n + 1) / 2 - 1;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i].s) {
            if (a[i].f + k < a[n - 1].f) break;
            int new_med;
            if (n&1) {
                if (i < med) new_med = med;
                else new_med = med - 1;
            } else {
                if (i <= med) new_med = med + 1;
                else new_med = med;
            }
            ans = max(ans, a[i].f + k + a[new_med].f);
        }
    }
    ans = max(ans, calc());
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

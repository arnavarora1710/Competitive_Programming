// https://codeforces.com/contest/1973/problem/C
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

int score(vector<int> b) {
    int cnt = 0;
    for (int i = 1; i < n - 1; ++i) 
        cnt += (b[i] > max(b[i - 1], b[i + 1]));
    return cnt;
}

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    vector<pi> odd, even;
    for (int i = 0; i < n; ++i) {
        if (i&1) odd.push_back({a[i], i});
        else even.push_back({a[i], i});
    }
    sort(odd.begin(), odd.end(), greater<pi>());
    sort(even.begin(), even.end(), greater<pi>());
    vector<int> c(n), d(n);
    int j = 1;
    for (int i = 0; i < even.size(); ++i, ++j)
        c[even[i].s] = j;
    for (int i = 0; i < odd.size(); ++i, ++j) 
        c[odd[i].s] = j;
    j = 1;
    for (int i = 0; i < odd.size(); ++i, ++j) 
        d[odd[i].s] = j;
    for (int i = 0; i < even.size(); ++i, ++j)
        d[even[i].s] = j;
    vector<int> e(n), f(n);
    for (int i = 0; i < n; ++i) {
        e[i] = c[i] + a[i];
        f[i] = d[i] + a[i];
    }
    // cerr << score(e) << ' ' << score(f) << '\n';
    if (score(e) > score(f)) {
        for (int i : c) cout << i << ' ';
        cout << '\n';
    } else {
        for (int i : d) cout << i << ' ';
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

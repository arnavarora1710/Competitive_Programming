// https://codeforces.com/contest/977/problem/F
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (0)
const int maxn = 2e5 + 5, inf = 1e18;
int n, a[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    map<int, pi> m; vector<int> p(n);
    m[a[0]] = {1, 0}; p[0] = 0;
    int ans = 1, index = 0;
    for (int i = 1; i < n; ++i) {
        if (m.count(a[i] - 1)) {
            auto v = m[a[i] - 1];
            m[a[i]] = {v.f + 1, i};
            p[i] = v.s;
        } else {
            if (!m.count(a[i]))
                m[a[i]] = {1, i};
            p[i] = i;
        }
        if (ans < m[a[i]].f) {
            ans = m[a[i]].f;
            index = i;
        }
    }
    cout << ans << '\n';
    vector<int> path;
    while (p[index] != index) 
        path.push_back(index + 1), index = p[index];
    path.push_back(index + 1);
    reverse(path.begin(), path.end());
    for (int& x : path) cout << x << ' ';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

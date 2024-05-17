// https://codeforces.com/contest/1814/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair
#define MULTI_TEST (1)
const int maxn = 2e5 + 5, inf = 1e18;
int n, x, y, a[maxn];

void print(vector<int> b) {
    cout << b.size() << ' ';
    for (int i : b) cout << i << ' ';
    cout << '\n';
}

void solve() {
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<pi> b(n);
    for (int i = 0; i < n; ++i) b[i] = mp(a[i], i + 1);
    sort(b.begin(), b.end(), greater<pi>());

    vector<int> ans1, ans2;

    for (int i = 0; i < n; ++i) {
        int c1 = x * b[i].f * (ans1.size() + 1);
        int c2 = y * b[i].f * (ans2.size() + 1);
        if (c1 < c2) ans1.push_back(b[i].s);
        else ans2.push_back(b[i].s);
    }

    print(ans1); print(ans2);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

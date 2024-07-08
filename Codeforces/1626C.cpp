// https://codeforces.com/contest/1626/problem/C
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
int n, k[maxn], h[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> k[i];
    for (int i = 0; i < n; ++i) cin >> h[i];
    vector<pi> b; b.push_back({k[0], h[0]});
    for (int i = 1; i < n; ++i) {
        pi val = {k[i], h[i]};
        pi popper;
        bool ok = 0;
        while (!b.empty() && k[i] - h[i] + 1 <= b.back().f) {
            ok = 1;
            popper = b.back();
            b.pop_back();
        }
        if (ok) {
            pi val1 = {val.f, max(popper.s + k[i] - popper.f, val.s)};
            b.push_back(val1);
        }
        else b.push_back(val);
    }
    int ans = 0;
    for (auto& v : b) ans += (v.s * (v.s + 1)) / 2;
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

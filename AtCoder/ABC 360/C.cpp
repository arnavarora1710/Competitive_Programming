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
int n, a[maxn], b[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    map<int, vector<int>> m;
    for (int i = 0; i < n; ++i) m[a[i]].push_back(b[i]);
    for (auto& v : m) sort(v.s.begin(), v.s.end());
    int ans = 0;
    for (auto& v : m) {
        for (int i = 0; i + 1 < v.s.size(); ++i) ans += v.s[i];
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

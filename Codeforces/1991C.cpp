// https://codeforces.com/contest/1991/problem/C
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

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> ans;
    for (int i = 0; i < 40; ++i) {
        int mx = *(max_element(a, a + n));
        int x = ((mx + 1) / 2);
        for (int j = 0; j < n; ++j) a[j] = abs(a[j] - x);
        ans.push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] != 0) {
            cout << -1 << '\n';
            return;
        }
    }
    cout << ans.size() << '\n';
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

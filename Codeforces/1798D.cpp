// https://codeforces.com/contest/1798/problem/D
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
const int maxn = 3e5 + 5, inf = 1e18;
int n, a[maxn];

void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    if (*(max_element(a, a + n)) == 0) {
        cout << "No\n";
        return;
    }
    vector<int> ans, pos, neg;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= 0) pos.push_back(a[i]);
        else neg.push_back(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (cur <= 0) {
            ans.push_back(pos.back());
            pos.pop_back();
        } else {
            ans.push_back(neg.back());
            neg.pop_back();
        }
        cur += ans.back();
    }
    cout << "Yes\n";
    for (int i : ans) cout << i << ' ';
    cout << '\n';
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

// https://codeforces.com/contest/632/problem/C
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (0)
const int maxn = 1e5 + 5, inf = 1e18;
int n;

bool cmp(string& a, string& b) {
    return a + b < b + a;
}

void solve() {
    cin >> n; vector<string> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end(), cmp);
    for (string s : a) cout << s;
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}

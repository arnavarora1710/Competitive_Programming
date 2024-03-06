// https://codeforces.com/problemset/problem/1516/B
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
int n, a[2005];

void submit(bool yes) {
    cout << (yes ? "YES\n" : "NO\n");
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> pr(n);
    pr[0] = a[0];
    for (int i = 1; i < n; ++i) 
        pr[i] = pr[i - 1] ^ a[i];
    bool yes = !pr[n - 1];
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            yes |= (pr[i] == (pr[j] ^ pr[i]) 
                    && pr[i] == (pr[n - 1] ^ pr[j]));
    submit(yes);
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
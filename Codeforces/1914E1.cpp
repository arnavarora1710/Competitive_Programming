// https://codeforces.com/contest/1914/problem/E1
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second
typedef pair<int, int> pi;
#define MULTI_TEST (1)
const int maxn = 2e5 + 5;
int n, aa, bb;
pi a[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i].s;
    for (int i = 0; i < n; ++i) cin >> a[i].f;
    int score = 0;
    for (int i = 0; i < n; ++i)
        score += a[i].s - a[i].f;
    vector<pi> c;
    for (int i = 0; i < n; ++i)
        c.push_back({a[i].f + a[i].s - 2, i});
    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());
    for (int i = 0; i < n; ++i) {
        bool bob = i&1;
        if (bob) score += 1 - a[c[i].s].s;
        else score += a[c[i].s].f - 1;
    }
    cout << score << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
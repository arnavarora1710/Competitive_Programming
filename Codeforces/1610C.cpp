// https://codeforces.com/problemset/problem/1610/C
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pi;
#define f first
#define s second
#define MULTI_TEST (1)
int n; pi a[200005];

bool f(int m) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (m - 1 - a[i].f <= cnt && cnt <= a[i].s)
            cnt++;
    }
    return cnt >= m;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i].f >> a[i].s;
    int l = -1, r = n + 1;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (f(m)) l = m;
        else r = m;
    }
    cout << l << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
// https://codeforces.com/problemset/problem/1552/B
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (1)
const int maxn = 5e4 + 5;
int n, a[maxn][5];

void submit(int x) {
    cout << (!x ? -1 : x) << endl;
}

bool check(int i, int j) {
    int cnt = 0;
    for (int k = 0; k < 5; ++k) 
        cnt += (a[i][k] < a[j][k]);
    return cnt >= 3;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 5; ++j) cin >> a[i][j];
    int ans = 0;
    for (int i = 1; i < n; ++i)
        if (!check(ans, i)) ans = i;
    bool ok = 1;
    for (int i = 0; i < n; ++i) {
        if (i != ans) {
            if (!check(ans, i)) {
                ok = 0;
                break;
            }
        }
    }
    submit(ok ? ans + 1 : ok);
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    srand(time(NULL));

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}
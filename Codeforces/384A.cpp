// https://codeforces.com/problemset/problem/384/A
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MULTI_TEST (0)
int n; char a[1001][1001];

void solve() {
    cin >> n; bool flag = 1; int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (flag && !(j&1)) a[i][j] = 'C', cnt++;
            else if (!flag && j&1) a[i][j] = 'C', cnt++;
            else a[i][j] = '.';
        }
        flag = !flag;
    }
    cout << cnt << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cout << a[i][j];
        cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--) solve();

    return 0;
}